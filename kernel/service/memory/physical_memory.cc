/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physical_memory.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:37:04 by larlena           #+#    #+#             */
/*   Updated: 2024/10/07 20:41:45 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "physical_memory.hpp"
#include <array>
#include <algorithm>
#include <ranges>
#include <span>
#include <elf.h>
#include <__memory_resource/monotonic_buffer_resource.h>

namespace kfs {

using Page = ktl::array<uint8_t, 0x1000>;

namespace details {

PhysicalMemory::PhysicalMemory(multiboot_memory_map_t *addr, size_t length, multiboot_elf_section_header_table_t *elfsh) {
	auto&&	multiboot_mmap = std::span<multiboot_memory_map_t>(addr, addr + (length / sizeof(addr)));
	auto&&	elf_sh_range = std::span<Elf32_Shdr>(reinterpret_cast<Elf32_Shdr*>(elfsh->addr), reinterpret_cast<Elf32_Shdr*>(elfsh->addr) + elfsh->num)
		| std::views::transform([](auto&& elf_header) {
			return ((elf_header.sh_addr + elf_header.sh_size) & ~0x3FF) + 0x400;
		});
	auto&&	max_used_memory = *std::ranges::max_element(elf_sh_range);
	auto&&	range = multiboot_mmap
		| std::views::transform([max_used_memory](auto &&mr){
			PhysicalAddress begin = mr.addr;
			PhysicalAddress end = (mr.addr + mr.len) & ~0x3FF;

			begin = (begin & 0x3FF ? begin + 0x400 : begin) & ~0x3FF;
			end = end < begin ? end - 0x400 : end;
			if (begin < max_used_memory) {
				begin = max_used_memory;
			}
			return MemoryRange{begin, end};
		})
		| std::views::filter([](auto &&range){
			return range.begin < range.end;
		});

	for (auto it : range) {
		mMap.push_back(it);
	}
} // PhysicalMemory::PhysicalMemory(multiboot_memory_map_t*, size_t, multiboot_elf_section_header_table_t*)

PhysicalAddress	PhysicalMemory::alloc() {
	if (mMap.empty())
		return 0;

	auto&&	map = mMap.front();
	PhysicalAddress	dest = map.begin;

	map.begin += chunk_size;
	if (map.begin == map.end)
		mMap.pop_front();

	return dest;
} // PhysicalMemory::alloc()


void	PhysicalMemory::dealloc(PhysicalAddress addr) {
	auto&&	memRange = MemoryRange(addr, addr + chunk_size);
	
	auto	leftNeighbor = std::lower_bound(mMap.begin(), mMap.end(), memRange);
	if (leftNeighbor == mMap.end()) {
		mMap.push_back(memRange);
		return ;
	}

	auto	rightNeighbor = std::upper_bound(leftNeighbor, mMap.end(), memRange);
	if (rightNeighbor == mMap.end()) {
		mMap.push_front(memRange);
		return ;
	}
	if (!memRange.adjacent(*leftNeighbor) && !memRange.adjacent(*rightNeighbor)) {
		mMap.insert(rightNeighbor, memRange);
	}

	memRange.merge(*leftNeighbor);
	memRange.merge(*rightNeighbor);
	if (leftNeighbor->adjacent(*rightNeighbor)) {
		leftNeighbor->merge(*rightNeighbor);
		mMap.erase(rightNeighbor);
	}
} // PhysicalMemory::dealloc(PhysicalAddress addr)

} // namespace details

}
