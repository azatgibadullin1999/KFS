/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physical_memory.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:37:04 by larlena           #+#    #+#             */
/*   Updated: 2025/09/23 15:40:13 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <cstdio>
#include <span>
#include <ranges>
#include <cstddef>

#include <elf.h>
#include <stdexcept>

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
} { }


phys_addr_t	PhysicalMemory::alloc() {
	if (_memory.empty())
		return 0;

	

	return 0;
}

void	PhysicalMemory::dealloc(phys_addr_t addr) { }

} // namespace details

}
