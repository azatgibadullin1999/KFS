/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physical_memory.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:37:04 by larlena           #+#    #+#             */
/*   Updated: 2025/06/16 21:38:37 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "physical_memory.hpp"

#include <array>
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <ranges>
#include <span>
#include <elf.h>
#include <__memory_resource/monotonic_buffer_resource.h>

#include "arch/kerneldef.h"
#include "memory_range.hpp"

namespace kfs {

namespace details {

PhysicalMemory::PhysicalMemory(multiboot_memory_map_t *addr, size_t length, multiboot_elf_section_header_table_t *elfsh) {
	auto&&	toMemoryRange = [](auto &&mr){
		PhysicalAddress begin = mr.addr >> 12;
		PhysicalAddress end = begin + (mr.len >> 12) + (bool)(mr.len & ~0xFFFFF000);

		return MemoryRange(begin, end);
	};

	auto&&	range = std::span<multiboot_memory_map_t>(addr, addr + (length / sizeof(multiboot_memory_map_t)))
		| std::views::transform(toMemoryRange);

	for (auto it : range) {
		memory.push_back(it);
	}
}


PhysicalAddress	PhysicalMemory::alloc() {
	if (memory.empty())
		return 0;

	auto&&	mem_range = memory.front();
	auto&&	new_mem_range = MemoryRange(++mem_range.begin, mem_range.end);
	PhysicalAddress	dest = mem_range.begin << 12;

	if (new_mem_range.begin == new_mem_range.end)
		memory.pop_front();
	else
	 	memory.front() = new_mem_range;

	return dest;
}

void	PhysicalMemory::dealloc(PhysicalAddress addr) {
	auto&&	memRange = MemoryRange(addr >> 12, (addr >> 12) + 1);

	auto	lhs = std::lower_bound(std::begin(memory), std::end(memory), memRange);
	if (lhs == memory.end()) {
		memory.push_back(memRange);
		return ;
	}

	auto	rhs = std::upper_bound(lhs, memory.end(), memRange);
	if (rhs == memory.end()) {
		memory.push_front(memRange);
		return ;
	}
	if (not adjacent(memRange, *lhs) && !adjacent(memRange, *rhs)) {
		memory.insert(rhs, memRange);
	}

	memRange = merge(memRange, *lhs);
	memRange = merge(memRange, *rhs);
	if (adjacent(*lhs, *rhs)) {
		*lhs = merge(*lhs, *rhs);
		memory.erase(rhs);
	}
}

} // namespace details

}
