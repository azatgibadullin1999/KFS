/**
 * @file address_space.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 26-09-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#include <exception>
#include <memory>
#include <ranges>
#include <span>
#include <array>
#include <limits>
#include <cstddef>
#include <algorithm>

#include <arch/kerneldef.h>
#include <service/memory/paging.hpp>
#include <service/memory/physical_memory.hpp>

#include "address_space.hpp"

namespace kfs {

constexpr std::size_t page_directory_mapping_address = std::numeric_limits<std::size_t>::max() - ~(kfs::page::page_mask);
constexpr std::size_t page_tables_mapping_address = std::numeric_limits<std::size_t>::max() - (kfs::page::page_size * 1024 - 1);

AddressSpace::AddressSpace(page::Page::MemoryMapping page_directory)
: _page_directory{ page_directory } {
	auto&& directory = get_page_directory().entrys();

	std::ranges::for_each(directory, [](auto &&entry) {
		entry.set(nullptr)
			.phys_addr(0)
			.read_write(false)
			.present(false);
	});

	directory.back().set(nullptr)
		.phys_addr(_page_directory.physical_address)
		.read_write(true)
		.present(true);
}

void AddressSpace::load() noexcept {
	_page_directory.virtual_address = reinterpret_cast<page::Page *>(page_directory_mapping_address);
	asm volatile (
	"mov %0, %%cr3\n\t"
		:
		: "a"(_page_directory.physical_address));
}

std::span<page::Table> AddressSpace::get_page_tables() noexcept {
	return std::span<page::Table>{
		*reinterpret_cast<std::array<page::Table, 1023>*>(page_tables_mapping_address)
	};
}

page::Directory &AddressSpace::get_page_directory() noexcept {
	return *reinterpret_cast<page::Directory *>(_page_directory.virtual_address);
}

phys_addr_t AddressSpace::get_page_directory_physical_address() noexcept {
	return _page_directory.physical_address;
}

virt_addr_t AddressSpace::allocate() {
	auto&& directory = get_page_directory().entrys();
	auto&& tables = get_page_tables();

	auto&& enumirate = std::views::iota(0uz, 1023uz);
	auto&& dit = std::ranges::find_if(enumirate, [&directory](auto&& di) { return !directory[di].is_kfs_full() && directory[di].is_present(); });
	if (dit == std::ranges::end(enumirate)) {
		dit = std::ranges::find_if(enumirate, [&directory](auto &&di) { return !directory[di].is_present(); });
		if (dit == std::ranges::end(enumirate))
			std::terminate();
		directory[*dit].set(std::addressof(get_page_tables()[*dit]))
			.phys_addr(PhysicalMemory::instance().allocate())
			.present(true);
	}
	auto &&table = tables[*dit].entrys();
	auto &&tit = std::ranges::find_if(enumirate, [&table](auto&& ti) { return !table[ti].is_present(); });

	table[*tit].set(reinterpret_cast<virt_addr_t>(*dit << 22 | *tit << 12))
		.phys_addr(PhysicalMemory::instance().allocate())
		.present(true);

	return reinterpret_cast<virt_addr_t>(*dit << 22 | *tit << 12);
}

void AddressSpace::deallocate(virt_addr_t memory) {
	std::size_t di = reinterpret_cast<std::size_t>(memory)       >> 22;
	std::size_t ti = reinterpret_cast<std::size_t>(memory) << 12 >> 22;

	auto &&entry = get_page_tables()[di].entrys()[ti];
	entry.set(memory).present(false).present(false);

	PhysicalMemory::instance().deallocate(entry.get_phys_addr());
}

}
