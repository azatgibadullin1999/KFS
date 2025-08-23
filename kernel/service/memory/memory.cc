/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.cc                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:11:15 by larlena           #+#    #+#             */
/*   Updated: 2025/04/04 15:25:40 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.hpp"
#include "imp/init_x86.hpp"
#include "physical_memory.hpp"
#include "page_manager.hpp"
#include "address_space.hpp"
#include "arch/x86/gdt_default.hpp"

Memory	Memory::init(multiboot_memory_map_t *addr, size_t length, multiboot_elf_section_header_table_t *elfsh) {
	static auto&&	memory = Memory();

	kfs::PhysicalMemory::instance().init(addr, length, elfsh);
	auto&&	gdt [[maybe_unused]] = kfs::x86::GDTDefault{};
	auto&&	[directory, table] = kfs::x86::page::initial::init_paging();

	auto&&	address_space = kfs::AddressSpace{*directory.second};
	auto&&	page_manager [[maybe_unused]] = kfs::x86::page::Manager(table);

	return memory;
}
