/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physical_memory.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:02:55 by larlena           #+#    #+#             */
/*   Updated: 2024/07/06 14:00:35 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_PHYSICAL_MEMORY_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_PHYSICAL_MEMORY_HPP__

# include "../boot/multiboot.h"
# include "common/singleton.hpp"
# include <cstdint>
# include <list>

namespace kfs {

using PhysicalAddress = size_t;

namespace details {

class PhysicalMemory {
public:
	PhysicalMemory() { }
	PhysicalMemory(multiboot_memory_map_t *addr, size_t length, multiboot_elf_section_header_table_t *elfsh);

	PhysicalAddress	alloc();
	void	dealloc(PhysicalAddress);
private:
	using pair = std::pair<PhysicalAddress, PhysicalAddress>;

	std::pmr::list<pair>	mMap;
	static const inline size_t	chunk_size = 0x400;
}; // class PhysicalMemory

} // namespace details

using PhysicalMemorySingleton = kfs::interface::DynamicSingletonWrapper<details::PhysicalMemory>;

} // namespace kfs

#endif // __KFS_KERNEL_SERVICE_MEMORY_PHYSICAL_MEMORY_HPP__
