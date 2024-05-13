/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paging.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:17:49 by larlena           #+#    #+#             */
/*   Updated: 2024/05/26 16:38:25 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_ARCH_X86_PAIGING_HPP__
# define __KFS_KERNEL_ARCH_X86_PAIGING_HPP__

# include <stdint.h>
# include "utils/stl/array.hpp"
# include "utils/stl/bitset.hpp"

namespace kfs::x86 {

namespace experimental {

struct PageFlags {
public:
	auto	accesed() noexcept {
		return flags[5];
	}
	auto	page_cache_disable() noexcept {
		return flags[4];
	}
	auto	page_write_through() noexcept {
		return flags[3];
	}
	auto	user_supervisor() noexcept {
		return flags[2];
	}
	auto	read_write() noexcept {
		return flags[1];
	}
	auto	present() noexcept {
		return flags[0];
	}
protected:
	ktl::bitset<8>	flags [[no_unique_address]];
};

struct [[gnu::packed]] PageDirectoryFlags : public PageFlags {
	auto	page_size() noexcept {
		return flags[7];
	}
	auto	avaliable() noexcept {
		return flags[6];
	}
};

struct [[gnu::packed]] PageTableFlags : public PageFlags {
	auto	page_atribute_table() noexcept {
		return flags[7];
	}
	auto	dirty() noexcept {
		return flags[6];
	}
};

} // namespace experimental

namespace detail {

struct [[gnu::packed]] PageDirectoryFlags {
	uint8_t	present:1;
	uint8_t	read_write:1;
	uint8_t	user_supervisor:1;
	uint8_t	page_write_through:1;
	uint8_t	page_cache_disable:1;
	uint8_t	accesed:1;
	uint8_t	avaliable:1;
	uint8_t	page_size:1;
};

struct [[gnu::packed]] PageTableFlags {
	uint8_t	present:1;
	uint8_t	read_write:1;
	uint8_t	user_supervisor:1;
	uint8_t	page_write_through:1;
	uint8_t	page_cache_disable:1;
	uint8_t	accesed:1;
	uint8_t	dirty:1;
	uint8_t	page_atribute_table:1;
};

struct [[gnu::packed]] PageDirectory4KB {
	PageDirectoryFlags	flags;
	uint8_t			avaliable:4;
	uint8_t			base_low:4;
	uint16_t		base_high;
};

struct [[gnu::packed]] PageTable {
	PageTableFlags	flags;
	uint8_t		global:1;
	uint8_t		avaliable:3;
	uint8_t		base_low:4;
	uint16_t	base_high;
};

const inline uint32_t	address_mask = 0xFFFFF000;

} // namespace detail

class [[gnu::packed]] PageTable : public detail::PageTable {
public:
	void	setBaseAddress(uint32_t address) noexcept {
		base_low = address >> 12;
		base_high = address >> 16;
	}
	operator uint32_t() noexcept {
		return *reinterpret_cast<uint32_t *>(this);
	}
};

class [[gnu::packed]] PageDirectory : public detail::PageDirectory4KB {
public:
	void	setTableBaseAddress(const PageTable *table) noexcept {
		base_low = reinterpret_cast<uint32_t>(table) >> 12;
		base_high = reinterpret_cast<uint32_t>(table) >> 16;
	}
	operator uint32_t() noexcept {
		return *reinterpret_cast<uint32_t *>(this);
	}
};

} // namespace kfs::x86

#endif // __KFS_KERNEL_ARCH_X86_PAIGING_HPP__
