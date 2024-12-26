/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physical_memory.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:37:04 by larlena           #+#    #+#             */
/*   Updated: 2024/12/26 12:04:15 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "service/memory/memory_range.hpp"
#include "physical_memory.hpp"
#include <array>
#include <algorithm>
#include <cstddef>
#include <ranges>
#include <span>
#include <elf.h>
#include <__memory_resource/monotonic_buffer_resource.h>

namespace kfs {

using Page = ktl::array<uint8_t, 0x1000>;


namespace details {

PhysicalMemory::PhysicalMemory(multiboot_memory_map_t *addr, size_t length, multiboot_elf_section_header_table_t *elfsh) {
	auto&&	multiboot_mmap = std::span<multiboot_memory_map_t>(addr, addr + (length / sizeof(multiboot_memory_map_t)));
	
		// auto&&	elf_sh_range = std::span<Elf32_Shdr>(reinterpret_cast<Elf32_Shdr*>(elfsh->addr), reinterpret_cast<Elf32_Shdr*>(elfsh->addr) + elfsh->num)
	// 	| std::views::transform([](auto&& elf_header) {
	// 		return MemoryRange((elf_header.sh_addr >> 12), (elf_header.sh_addr >> 12) + (elf_header.sh_size >> 12) + (bool)(elf_header.sh_size & ~0xFFFFF000));
	// 	})
	// 	| std::views::filter([](auto&& mr){
	// 		static MemoryRange	prev{0,0};
	// 		bool ret = mr != prev;
	// 		prev = mr;
	// 		return ret;
	// 	});
	
	auto&&	range = multiboot_mmap
		| std::views::transform([](auto &&mr){
			phys_addr_t begin = mr.addr >> 12;
			phys_addr_t end = begin + (mr.len >> 12) + (bool)(mr.len & ~0xFFFFF000);
			return MemoryRange{begin, end};
		});

	for (auto it : range) {
		mMap.push_back(it);
	}
} // PhysicalMemory::PhysicalMemory(multiboot_memory_map_t*, size_t, multiboot_elf_section_header_table_t*)


phys_addr_t	PhysicalMemory::alloc() {
	if (mMap.empty())
		return 0;

	auto&&	map = mMap.front();
	phys_addr_t	dest = map.begin << 12;

	if (++map.begin == map.end)
		mMap.pop_front();

	return dest;
} // PhysicalMemory::alloc()

phys_addr_t	PhysicalMemory::alloc(MemoryRange range) {
	if (mMap.empty())
		return 0;

	auto&&	it = std::ranges::find_if(mMap, [&range](auto&& rangeElem) {
		return intersected(range, rangeElem);
	});
	auto&&	allocatiableRange = std::ranges::iota_view(range.begin, [range.end](auto begin) {return });

	if (it == mMap.end()) {
		return 0;
	}
	auto&&	pair = exclude(*it, range);
	*it = valid(pair.first) ? pair.first : pair.second;
	if (valid(pair.first) && valid(pair.second)) {
		mMap.insert(++it, pair.second);
	}
	return range.begin;
} // PhysicalMemory::alloc(MemoryRange range)


void	PhysicalMemory::dealloc(phys_addr_t addr) {
	auto&&	memRange = MemoryRange(addr >> 12, (addr >> 12) + 1);
	
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
	if (!adjacent(memRange, *leftNeighbor) && !adjacent(memRange, *rightNeighbor)) {
		mMap.insert(rightNeighbor, memRange);
	}

	memRange = merge(memRange, *leftNeighbor);
	memRange = merge(memRange, *rightNeighbor);
	if (adjacent(*leftNeighbor, *rightNeighbor)) {
		*leftNeighbor = merge(*leftNeighbor, *rightNeighbor);
		mMap.erase(rightNeighbor);
	}
} // PhysicalMemory::dealloc(phys_addr_t addr)

} // namespace details

}
