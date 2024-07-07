/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.cc                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:11:15 by larlena           #+#    #+#             */
/*   Updated: 2024/07/06 14:05:12 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.hpp"
#include "imp/init_x86.hpp"
#include "physical_memory.hpp"

Memory	Memory::init(multiboot_memory_map_t *addr, size_t length, multiboot_elf_section_header_table_t *elfsh) {
	static auto&&	memory = Memory();

	// auto&&	physical_memory [[maybe_unused]] = 
	kfs::PhysicalMemorySingleton::init(addr, length, elfsh);
	auto&&	table [[maybe_unused]] = kfs::x86::GDTDefault();
	auto&&	paging [[maybe_unused]] = InitialPaging();
	// auto&&	page_manager [[maybe_unused]] = PageManager();

	return memory;
}
