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

#ifndef KFS_KERNEL_SERVICE_MEMORY_MEMORY_HPP
# define KFS_KERNEL_SERVICE_MEMORY_MEMORY_HPP

# include <stddef.h>

# include <multiboot.h>

namespace kfs {

using virt_addr_t = void *;
using phys_addr_t = std::size_t;

class Memory {
public:
	static Memory	init(multiboot_memory_map_t *addr, size_t len);
private:
};

} // namespace kfs

#endif // KFS_KERNEL_SERVICE_MEMORY_MEMORY_HPP
