/**
 * @file address_space.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_ADDRESS_SPACE_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_ADDRESS_SPACE_HPP__

# include <span>

# include "arch/kerneldef.h"
# include "service/memory/paging.hpp"

namespace kfs {

struct AddressSpace {
	AddressSpace(page::Page::MemoryMapping page_directory);

	void load() noexcept;

	virt_addr_t allocate();
	void deallocate(virt_addr_t memory);

protected:
	std::span<page::Table> _get_page_tables() const noexcept;
	page::Directory &_get_page_directory() const noexcept;
	phys_addr_t _get_page_directory_physical_address() const noexcept;
private:
	page::Page::MemoryMapping _page_directory;
};

}

#endif // __KFS_KERNEL_SERVICE_MEMORY_ADDRESS_SPACE_HPP__
