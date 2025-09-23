/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_x86.cc                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:17:54 by larlena           #+#    #+#             */
/*   Updated: 2025/09/23 15:41:10 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "init_x86.hpp"
# include "arch/kerneldef.h"
# include "arch/x86/paging.hpp"
# include <array>
# include <memory>
# include <algorithm>
# include <bit>

namespace kfs::x86::page::initial {

page::Directory&	getDirectory() {
	static page::Directory	directory [[gnu::section(".bss")]] [[gnu::aligned(0x1000)]];

	std::ranges::for_each(directory.getEntrys(), [](auto &&entry) {
		entry.read_write = true;
		entry.setPhysAddr(0);
	});

	return directory;
}

page::Table&	getTable() {
	static page::Table	table [[gnu::section(".bss")]] [[gnu::aligned(0x1000)]];\
	size_t index = 0;

	std::ranges::for_each(table.getEntrys(), [&index](auto &&entry) {
		entry.present = true;
		entry.read_write = true;
		entry.setPhysAddr(index++ * 0x1000);
	});
	return table;
}

void init_paging() noexcept {
	auto &&directory = getDirectory();
	auto &&firstDirectoryEntry = directory.getEntrys().begin();
	auto &&table = getTable();

	firstDirectoryEntry->setPhysAddr(std::bit_cast<phys_addr_t>(table.getEntrys().data()));
	firstDirectoryEntry->present = true;

	auto &&last = std::prev(directory.getEntrys().end());
	last->setPhysAddr(reinterpret_cast<phys_addr_t>(std::addressof(directory)));
	last->present = true;

	last = std::prev(last);
	last->setPhysAddr(reinterpret_cast<phys_addr_t>(std::addressof(table)));
	last->present = true;


	asm volatile (
	"mov %0, %%cr3\n\t"
		:
		: "a"(directory.getEntrys().data()));

	asm volatile (
	"mov %cr0, %eax\n\t"
	"or $0x80000000, %eax\n\t"
	"mov %eax, %cr0\n\t"
	);
}

}