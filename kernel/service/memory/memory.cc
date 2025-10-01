/**
 * @file memory.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <cstddef>
#include <span>
#include <cstdio>

#include <elf.h>
#include <service/memory/memory_range.hpp>

#include "memory.hpp"
#include "gdt_default.hpp"
#include "physical_memory.hpp"
#include "imp/kernel_address_space.hpp"

namespace kfs {

Memory	Memory::init(multiboot_memory_map_t *addr, size_t length, multiboot_elf_section_header_table_t *elfsh) {
	std::span<multiboot_memory_map_t> memory_map{
		addr,
		addr + length / sizeof(multiboot_memory_map_t)
	};
	
	static auto&&	memory = Memory();

	PhysicalMemory::instance().init(memory_map);
	static auto&&	gdt [[maybe_unused]] = x86::GDTDefault{};
	static auto&&	address_space = KernelAddressSpace{ };
	
	return memory;
}

} // namespace kfs
