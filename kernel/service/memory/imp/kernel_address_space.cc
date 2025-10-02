/**
 * @file kernel_address_space.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <ranges>

#include "arch/kerneldef.h"
#include "service/memory/paging.hpp"
#include "service/memory/address_space.hpp"
#include "service/memory/physical_memory.hpp"

#include "kernel_address_space.hpp"

namespace kfs {

struct InitialMemoryMapping : page::Page::MemoryMapping {
	InitialMemoryMapping(phys_addr_t addr)
	: page::Page::MemoryMapping{
		reinterpret_cast<page::Page *>(addr),
		addr
	} { }
};

KernelAddressSpace::KernelAddressSpace()
: AddressSpace{ InitialMemoryMapping{ PhysicalMemory::instance().allocate() } } {
	std::span<page::Directory::Entry> directory = reinterpret_cast<page::Directory *>(_get_page_directory_physical_address())->entrys();

	directory.front().set(nullptr)
		.phys_addr(PhysicalMemory::instance().allocate())
		.read_write(true)
		.present(true)
		.kfs_full(true);

	std::span<page::Table::Entry> table = reinterpret_cast<page::Table *>(directory.front().get_phys_addr())->entrys();

	for (auto &&index : std::views::iota(0zu, 1024zu)) {
		table[index].set(nullptr)
			.phys_addr(index << 12)
			.read_write(true)
			.present(true);
	}

	load();

	asm volatile (
	"mov %cr0, %eax\n\t"
	"or $0x80000000, %eax\n\t"
	"mov %eax, %cr0\n\t"
	);
}

}
