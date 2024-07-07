/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physical_memory.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:37:04 by larlena           #+#    #+#             */
/*   Updated: 2024/06/28 18:23:06 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "physical_memory.hpp"
#include <array>
#include <algorithm>
#include <ranges>
#include <span>
#include <__memory_resource/monotonic_buffer_resource.h>

namespace kfs {

using Page = ktl::array<uint8_t, 0x1000>;

namespace details {

auto	get_memory_resource() {
	static ktl::array<uint8_t, 0x1000>	memory;
	static auto&&	initial_memory = std::pmr::monotonic_buffer_resource(memory.data(), memory.size(), nullptr);

	return &initial_memory;
}

PhysicalMemory::PhysicalMemory(multiboot_memory_map_t *addr, size_t length, multiboot_elf_section_header_table_t *elfsh) :
	mMap(details::get_memory_resource()) {
	auto&&	multiboot_mmap = std::span<multiboot_memory_map_t>(addr, addr + (length / sizeof(addr)));
	auto&&	range = multiboot_mmap
		| std::views::transform([](auto &&mr){
			PhysicalAddress begin = mr.addr;
			PhysicalAddress end = (mr.addr + mr.len) & ~0x3FF;

			begin = (begin & 0x3FF ? begin + 0x400 : begin) & ~0x3FF;
			end = end < begin ? end - 0x400 : end;
			if (begin < 0x400000) {
				begin = 0x400000;
			}
			return std::make_pair(begin, end);
		})
		| std::views::filter([](auto &&pair){
			return pair.first < pair.second;
		});

	for (auto it : range) {
		mMap.push_back(it);
	}
} // PhysicalMemory::PhysicalMemory(multiboot_memory_map_t*, size_t, multiboot_elf_section_header_table_t*)

PhysicalAddress	PhysicalMemory::alloc() {
	if (mMap.empty())
		return 0;

	auto&&	map = mMap.front();
	PhysicalAddress	dest = map.first;

	map.first += chunk_size;
	if (map.first <= map.second)
		mMap.pop_front();

	return dest;
} // PhysicalMemory::alloc()


void	PhysicalMemory::dealloc(PhysicalAddress addr) {
	auto	itPrev = std::ranges::find_if(mMap,
			[addr](auto &addr2){ return addr < addr2; },
			&pair::first);
	auto	itNext = itPrev == mMap.begin() ? itPrev : itPrev-- ;
	uint8_t	flag = 0;

	if (itNext == mMap.end()) {
		mMap.push_back(std::make_pair(addr, addr + chunk_size));
	} else {
		if (itNext->first == addr + chunk_size) {
			itNext->first = addr;
			++flag;
		}
		if (itPrev->second == addr) {
			itPrev->second += chunk_size;
			++flag;
		}
		if (itNext->first == itPrev->second) {
			itPrev->second = itNext->second;
			mMap.erase(itNext);
		}
		if (!flag) {
			mMap.insert(itNext, std::make_pair(addr, addr + chunk_size));
		}
	}
}

} // namespace details

}

