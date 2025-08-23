/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_x86.cc                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:17:54 by larlena           #+#    #+#             */
/*   Updated: 2025/04/04 15:04:27 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "init_x86.hpp"
#include "arch/kerneldef.h"
#include "arch/x86/paging.hpp"
#include <array>
#include <memory>
#include <algorithm>
#include <__bit/bit_cast.h>

namespace kfs::x86::page::initial {

page::Directory&	getDirectory() {
	static page::Directory	directory [[gnu::section(".bss")]] [[gnu::aligned(0x1000)]];

	std::ranges::for_each(directory.entrys, [](auto &&entry) {
		entry.read_write = true;
		entry.set_phys_addr(0);
	});
	return directory;
}

page::Table&	getTable() {
	static page::Table	table [[gnu::section(".bss")]] [[gnu::aligned(0x1000)]];\
	size_t index = 0;

	std::ranges::for_each(table.entrys, [&index](auto &&entry) {
		entry.present = true;
		entry.read_write = true;
		entry.set_phys_addr(index++ * 0x1000);
	});
	return table;
}

std::pair<page::Directory::Pair, page::Table::Pair>	init_paging() noexcept {
	auto &&directory = getDirectory();
	auto &&directoryEntry = directory.entrys[0];
	auto &&initialTable = getTable();

	directoryEntry.present = true;
	directoryEntry.set_phys_addr(std::bit_cast<PhysicalAddress>(initialTable.entrys.data()));

	asm volatile (
	"mov %0, %%cr3\n\t"
		:
		: "a"(directory.entrys.data()));

	asm volatile (
	"mov %cr0, %eax\n\t"
	"or $0x80000000, %eax\n\t"
	"mov %eax, %cr0\n\t"
	);
	return {
		{std::bit_cast<PhysicalAddress>(std::addressof(directory)),   std::addressof(directory)},
		{std::bit_cast<PhysicalAddress>(std::addressof(initialTable)),std::addressof(initialTable)}
	};
}

}