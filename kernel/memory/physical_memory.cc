/**
 * @file physical_memory.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <span>
#include <ranges>
#include <cstddef>

#include <elf.h>

#include <kfs/memory.hpp>
#include "memory_range.hpp"
#include "physical_memory.hpp"

namespace kfs {

namespace details {

PhysicalMemory::PhysicalMemory(std::span<multiboot_memory_map_t> memory_map)
: _memory{
	  memory_map
	| std::views::filter([](auto &&map) {
		return map.type == MULTIBOOT_MEMORY_AVAILABLE;
	})
	| std::views::transform([](auto &&map) {
		return MemoryRange{
			static_cast<kfs::phys_addr_t>(map.addr >> 12),
			static_cast<kfs::phys_addr_t>((map.addr >> 12) + (map.len >> 12)), 
		};
	})
	| std::views::transform([](auto &&range) {
		if (range.end < 1024) {
			range.end = 0, range.begin = 0;
		} else if (range.begin < 1024) {
			range.begin = 1024;
		}
		return range;
	})
	| std::views::filter([](auto &&range) {
		return range.begin != 0 && range.end != 0;
	})
	| std::ranges::to<decltype(_memory)>()
}
, _used_chunks{
	  _memory
	| std::views::transform([](auto &&entry) {
		return std::views::iota(entry.begin, entry.end);
	})
	| std::views::join
	| std::views::transform([](auto &&index[[maybe_unused]]) {
		return 0;
	})
	| std::ranges::to<decltype(_used_chunks)>()
} {
}


kfs::phys_addr_t	PhysicalMemory::allocate() {
	if (_memory.empty()) {
		return 0;
	}

	for (auto &&tuple : std::views::zip(_memory | std::views::transform([](auto &&entry) { return std::views::iota(entry.begin, entry.end); }) | std::views::join, _used_chunks)) {
		auto &&[iaddr, used] = tuple;
		if (not used) {
			used = true;
			return iaddr << 12;
		}
	}
	return 0;
}

void	PhysicalMemory::deallocate(kfs::phys_addr_t memory) {
	memory >>= 12;
	for (auto &&tuple : std::views::zip(_memory | std::views::transform([](auto &&entry) { return std::views::iota(entry.begin, entry.end); }) | std::views::join, _used_chunks)) {
		auto &&[iaddr, used] = tuple;
		if (memory == iaddr) {
			used = false;
			return;
		}
	}
}

} // namespace details

}
