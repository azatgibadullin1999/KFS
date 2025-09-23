/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physical_memory.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:02:55 by larlena           #+#    #+#             */
/*   Updated: 2025/09/23 15:40:55 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_PHYSICAL_MEMORY_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_PHYSICAL_MEMORY_HPP__

# include <span>
# include <list>
# include <vector>
# include <cstddef>

# include "arch/kerneldef.h"
# include "multiboot.h"
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

	phys_addr_t	alloc();
	void	dealloc(phys_addr_t);
private:
	std::list<MemoryRange> _memory;
	std::list<std::vector<size_t>> _used_chunks;
	static const inline size_t _chunk_size = 0x400;
}; // class PhysicalMemory

} // namespace details

using PhysicalMemory = kfs::interface::singleton_wrapper<details::PhysicalMemory>;

} // namespace kfs

#endif // __KFS_KERNEL_SERVICE_MEMORY_PHYSICAL_MEMORY_HPP__
