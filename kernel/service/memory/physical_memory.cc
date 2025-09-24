/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physical_memory.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:37:04 by larlena           #+#    #+#             */
/*   Updated: 2025/09/24 22:05:40 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <span>
#include <ranges>
#include <cstddef>
#include <cstdio>

#include <elf.h>

#include "arch/kerneldef.h"
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
			static_cast<phys_addr_t>(map.addr >> 12),
			static_cast<phys_addr_t>((map.addr >> 12) + (map.len >> 12)), 
		};
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
} { }


phys_addr_t	PhysicalMemory::alloc() {
	if (_memory.empty())
		return 0;

	for (auto &&tuple : std::views::zip(_memory | std::views::transform([](auto &&entry) { return std::views::iota(entry.begin, entry.end); }) | std::views::join, _used_chunks)) {
		auto &&[iaddr, used] = tuple;
		if (used == false) {
			used = true;
			return iaddr << 12;
		}
	}
	return 0;
}

void	PhysicalMemory::dealloc(phys_addr_t addr) {
	addr >>= 12;
	for (auto &&tuple : std::views::zip(_memory | std::views::transform([](auto &&entry) { return std::views::iota(entry.begin, entry.end); }) | std::views::join, _used_chunks)) {
		auto &&[iaddr, used] = tuple;
		if (addr == iaddr) {
			used = false;
			return;
		}
	}
}

} // namespace details

}
