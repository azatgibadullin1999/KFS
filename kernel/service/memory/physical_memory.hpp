/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physical_memory.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:02:55 by larlena           #+#    #+#             */
/*   Updated: 2024/12/24 20:34:23 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_PHYSICAL_MEMORY_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_PHYSICAL_MEMORY_HPP__

# include "memory_range.hpp"
# include "arch/kerneldef.h"
# include "../boot/multiboot.h"
# include "common/singleton.hpp"
# include "ktypedef.h"
# include <list>
#include <ranges>

namespace kfs {

namespace details {

class PhysicalMemory {
public:
	PhysicalMemory() { }
	PhysicalMemory(multiboot_memory_map_t *addr, size_t length, multiboot_elf_section_header_table_t *elfsh);

	phys_addr_t	alloc();
	phys_addr_t	alloc(MemoryRange range);
	void	dealloc(phys_addr_t);
	void	showRange() {
		// printf("size of phys memory list = %d\n", mMap.size());
		// printf("list begin = %x , list end = %x\n", mMap.begin(), mMap.end());

		// for (auto&& it : mMap) {
		// 	printf("[range %x - %x]=>", it.begin, it.end);
		// }
	}
private:
	std::list<MemoryRange>	mMap;
	static const inline size_t	chunk_size = 0x400;
}; // class PhysicalMemory

} // namespace details

using PhysicalMemorySingleton = kfs::interface::DynamicSingletonWrapper<details::PhysicalMemory>;

} // namespace kfs

#endif // __KFS_KERNEL_SERVICE_MEMORY_PHYSICAL_MEMORY_HPP__
