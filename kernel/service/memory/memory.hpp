/**
 * @file memory.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_MEMORY_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_MEMORY_HPP__

# include <stddef.h>

# include <multiboot.h>

namespace kfs {

class Memory {
public:
	static Memory	init(multiboot_memory_map_t *addr, size_t len, multiboot_elf_section_header_table_t *elfsh);
private:
};

} // namespace kfs

#endif // __KFS_KERNEL_SERVICE_MEMORY_MEMORY_HPP__
