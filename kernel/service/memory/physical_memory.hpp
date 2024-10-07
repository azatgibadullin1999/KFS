/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physical_memory.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:02:55 by larlena           #+#    #+#             */
/*   Updated: 2024/08/28 12:33:17 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_PHYSICAL_MEMORY_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_PHYSICAL_MEMORY_HPP__

# include "memory_range.hpp"
# include "../boot/multiboot.h"
# include "common/singleton.hpp"
# include <list>

namespace kfs {

namespace details {

class PhysicalMemory {
public:
	PhysicalMemory() { }
	PhysicalMemory(multiboot_memory_map_t *addr, size_t length, multiboot_elf_section_header_table_t *elfsh);

	PhysicalAddress	alloc();
	void	dealloc(PhysicalAddress);
private:
	std::list<MemoryRange>	mMap;
	static const inline size_t	chunk_size = 0x400;
}; // class PhysicalMemory

} // namespace details

using PhysicalMemorySingleton = kfs::interface::DynamicSingletonWrapper<details::PhysicalMemory>;

} // namespace kfs

#endif // __KFS_KERNEL_SERVICE_MEMORY_PHYSICAL_MEMORY_HPP__
