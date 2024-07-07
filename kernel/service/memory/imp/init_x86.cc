/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_x86.cc                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:17:54 by larlena           #+#    #+#             */
/*   Updated: 2024/06/28 18:28:48 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "init_x86.hpp"

ktl::array<InitialPageDirectory, 0x400>&	get_page_directory() {
	static ktl::array<InitialPageDirectory, 0x400>	page_directory [[gnu::section(".bss")]] [[gnu::aligned(0x1000)]];
	return page_directory;
}

ktl::array<InitialPageTable, 0x400>&	get_page_table() {
	static ktl::array<InitialPageTable, 0x400>	page_table [[gnu::section(".bss")]] [[gnu::aligned(0x1000)]];
	return page_table;
}

InitialPageTable::InitialPageTable() noexcept {
	static size_t it = 0;
	flags.present = 1;
	flags.read_write = 1;
	setPhysicalAddress(it++ * 0x1000);
}

InitialPageDirectory::InitialPageDirectory() noexcept {
	flags.read_write = 1;
	setPhysicalAddress(0);
}

InitialPaging::InitialPaging() noexcept {
	get_page_directory()[0].setPhysicalAddress(reinterpret_cast<kfs::PhysicalAddress>(get_page_table().data()));
	get_page_directory()[0].flags.present = 1;

	asm volatile (
	"mov %0, %%cr3\n\t"
		:
		: "a"(get_page_directory().data()));

	asm volatile (
	"mov %cr0, %eax\n\t"
	"or $0x80000000, %eax\n\t"
	"mov %eax, %cr0\n\t"
	);
}