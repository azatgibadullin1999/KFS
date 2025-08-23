/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paging.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:17:49 by larlena           #+#    #+#             */
/*   Updated: 2025/06/20 22:01:55 by larlena          ###   ########.fr       */
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


const inline uint32_t	address_mask = 0xFFFFF000;

} // namespace detail

namespace page {

constexpr size_t size = 0x1000;


struct Page {
	ktl::array<uint8_t, size> data;
};
static_assert(sizeof(Page) == 0x1000, "");


using Pair = std::pair<PhysicalAddress, VirtualAddress>;

enum Type {
	eDefault,
	eDirectory,
	eTable,
};

struct MetaData {
	VirtualAddress virtAddr;
	PhysicalAddress physAddr;
};

template <typename UnitEntry>
concept MappingUnitEntry = requires(UnitEntry unit) {
	{ unit.present };
	{ unit.getPhysAddr() } -> std::same_as<PhysicalAddress>;
	{ unit.setPhysAddr(std::declval<PhysicalAddress>()) };
};

template <typename Unit>
concept MappingUnit = requires(Unit unit) {
	{ unit.getEntrys() };
};

struct Directory : Page {
	using Pair = std::pair<PhysicalAddress, Directory *>;
	struct Entry {
		void	setPhysAddr(PhysicalAddress address) noexcept {
			base_low = address >> 12;
			base_high = address >> 16;
		}
		PhysicalAddress	getPhysAddr() const noexcept {
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
	// ktl::array<Entry, 0x400> entrys;
};
static_assert(sizeof(Directory::Entry) == 4, "");
static_assert(sizeof(Directory) == 0x1000, "");

struct Table : Page {
	using Pair = std::pair<PhysicalAddress, Table *>;
	struct Entry {
		void	setPhysAddr(PhysicalAddress address) noexcept {
			base_low = address >> 12;
			base_high = address >> 16;
		}
		PhysicalAddress	getPhysAddr() const noexcept {
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
	// ktl::array<Entry, 0x400> entrys;
};
static_assert(sizeof(Table::Entry) == 4, "");
static_assert(sizeof(Table) == 0x1000, "");

template <MappingUnit Unit> size_t index(VirtualAddress addr);
template <> inline size_t index<Directory>(VirtualAddress addr) { return addr >> 22; }
template <> inline size_t index<Table>(VirtualAddress addr) { return (addr >> 12) & 0x3FF ; }

template <MappingUnit Unit> bool recursiveMapping(void);
template <> inline bool recursiveMapping<Directory>(void) { return true; }
template <> inline bool recursiveMapping<Table>(void) { return false; }

} // namespace page


} // namespace kfs::x86

#endif // __KFS_KERNEL_ARCH_X86_PAIGING_HPP__
