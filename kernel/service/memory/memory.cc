/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.cc                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:11:15 by larlena           #+#    #+#             */
/*   Updated: 2024/05/26 22:25:55 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.hpp"
#include "imp/init_x86.hpp"

Memory	Memory::init(multiboot_memory_map_t *addr, size_t len) {
	static auto&&	memory = Memory();

	auto&&	table [[maybe_unused]] = kfs::x86::GDTDefault();
	auto&&	paging [[maybe_unused]] = InitialPaging();

	return memory;
}

void*	get_preallocated_memory() {
	static ktl::array<uint8_t, 0x4000>	momory [[gnu::section(".bss")]] [[gnu::aligned(0x1000)]];
	return momory.data();
}
