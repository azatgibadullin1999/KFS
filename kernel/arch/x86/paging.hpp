/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paging.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:17:49 by larlena           #+#    #+#             */
/*   Updated: 2025/09/23 15:39:43 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_ARCH_X86_PAIGING_HPP__
# define __KFS_KERNEL_ARCH_X86_PAIGING_HPP__

#include <cstddef>
#include <span>
#include <stdint.h>
#include <bitset>
#include <array>
#include <utility>
#include "arch/kerneldef.h"

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
	std::bitset<8>	flags [[no_unique_address]];
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


const inline uint32_t	address_mask = 0xFFFFF000;

} // namespace detail

namespace page {

constexpr size_t size = 0x1000;


struct Page {
	std::array<uint8_t, size> data;
};
static_assert(sizeof(Page) == 0x1000, "");


using Pair = std::pair<phys_addr_t, virt_addr_t>;

enum Type {
	eDefault,
	eDirectory,
	eTable,
};

struct MetaData {
	virt_addr_t virtAddr;
	phys_addr_t physAddr;
};

template <typename UnitEntry>
concept MappingUnitEntry = requires(UnitEntry unit) {
	{ unit.present };
	{ unit.getPhysAddr() } -> std::same_as<phys_addr_t>;
	{ unit.setPhysAddr(std::declval<phys_addr_t>()) };
};

template <typename Unit>
concept MappingUnit = requires(Unit unit) {
	{ unit.getEntrys() };
};

struct Directory : Page {
	using Pair = std::pair<phys_addr_t, Directory *>;
	struct Entry {
		void	setPhysAddr(phys_addr_t address) noexcept {
			base_low = address >> 12;
			base_high = address >> 16;
		}
		phys_addr_t	getPhysAddr() const noexcept {
			return base_high << 16 | base_low << 12;
		}
		operator uint32_t() noexcept {
			return *reinterpret_cast<uint32_t *>(this);
		}
		uint8_t	present:1;
		uint8_t	read_write:1;
		uint8_t	user_supervisor:1;
		uint8_t	page_write_through:1;
		uint8_t	page_cache_disable:1;
		uint8_t	accesed:1;
		uint8_t	dirty:1;
		uint8_t	page_atribute_table:1;
		uint8_t	avaliable:4;
		uint8_t	base_low:4;
		uint16_t base_high;
	};

	auto getEntrys() {
		return std::span<Entry>(reinterpret_cast<Entry*>(data.begin()), reinterpret_cast<Entry*>(data.end()));
	}
	// std::array<Entry, 0x400> entrys;
};
static_assert(sizeof(Directory::Entry) == 4, "");
static_assert(sizeof(Directory) == 0x1000, "");

struct Table : Page {
	using Pair = std::pair<phys_addr_t, Table *>;
	struct Entry {
		void	setPhysAddr(phys_addr_t address) noexcept {
			base_low = address >> 12;
			base_high = address >> 16;
		}
		phys_addr_t	getPhysAddr() const noexcept {
			return base_high << 16 | base_low << 12;
		}
		operator uint32_t() noexcept {
			return *reinterpret_cast<uint32_t *>(this);
		}
		uint8_t	present:1;
		uint8_t	read_write:1;
		uint8_t	user_supervisor:1;
		uint8_t	page_write_through:1;
		uint8_t	page_cache_disable:1;
		uint8_t	accesed:1;
		uint8_t	dirty:1;
		uint8_t	page_atribute_table:1;
		uint8_t	global:1;
		uint8_t	avaliable:3;
		uint8_t	base_low:4;
		uint16_t base_high;
	};
	auto getEntrys() {
		return std::span<Entry>(reinterpret_cast<Entry*>(data.begin()), reinterpret_cast<Entry*>(data.end()));
	}
	// std::array<Entry, 0x400> entrys;
};
static_assert(sizeof(Table::Entry) == 4, "");
static_assert(sizeof(Table) == 0x1000, "");

template <MappingUnit Unit> size_t index(virt_addr_t addr);
template <> inline size_t index<Directory>(virt_addr_t addr) { return reinterpret_cast<size_t>(addr) >> 22; }
template <> inline size_t index<Table>(virt_addr_t addr) { return (reinterpret_cast<size_t>(addr) >> 12) & 0x3FF ; }

template <MappingUnit Unit> bool recursiveMapping(void);
template <> inline bool recursiveMapping<Directory>(void) { return true; }
template <> inline bool recursiveMapping<Table>(void) { return false; }

} // namespace page


} // namespace kfs::x86

#endif // __KFS_KERNEL_ARCH_X86_PAIGING_HPP__
