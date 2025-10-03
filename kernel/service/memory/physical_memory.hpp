/**
 * @file physical_memory.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef KFS_KERNEL_SERVICE_MEMORY_PHYSICAL_MEMORY_HPP
# define KFS_KERNEL_SERVICE_MEMORY_PHYSICAL_MEMORY_HPP

# include <span>
# include <list>
# include <vector>
# include <cstddef>

# include "multiboot.h"
# include "arch/kerneldef.h"
# include "common/singleton.hpp"

# include "memory_range.hpp"

namespace kfs {

namespace details {


class PhysicalMemory {
public:
	PhysicalMemory() = default;

	PhysicalMemory(std::span<multiboot_memory_map_t> memory_map);

	PhysicalMemory &init(std::span<multiboot_memory_map_t> memory_map) {
		*this = PhysicalMemory{memory_map};
		return *this;
	}

	phys_addr_t allocate();
	void deallocate(phys_addr_t memory);
private:
	std::list<MemoryRange> _memory;
	std::vector<bool> _used_chunks;
}; // class PhysicalMemory

} // namespace details

using PhysicalMemory = interface::SingletonWrapper<details::PhysicalMemory>;

} // namespace kfs

#endif // KFS_KERNEL_SERVICE_MEMORY_PHYSICAL_MEMORY_HPP
