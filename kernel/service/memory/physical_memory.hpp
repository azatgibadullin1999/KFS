/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physical_memory.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:02:55 by larlena           #+#    #+#             */
/*   Updated: 2025/06/16 22:00:44 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_PHYSICAL_MEMORY_HPP__
#define __KFS_KERNEL_SERVICE_MEMORY_PHYSICAL_MEMORY_HPP__

#include "memory_range.hpp"
#include "arch/kerneldef.h"
#include "../boot/multiboot.h"
#include "common/singleton.hpp"
#include <cstddef>
#include <list>

namespace kfs {

namespace details {

class PhysicalMemory {
public:
	PhysicalMemory() = default;

	PhysicalMemory(multiboot_memory_map_t *addr
		, size_t length
		, multiboot_elf_section_header_table_t *elfsh);

	PhysicalMemory &init(multiboot_memory_map_t *addr
		, size_t length
		, multiboot_elf_section_header_table_t *elfsh) {
		*this = PhysicalMemory{addr, length, elfsh};
		return *this;
	}

	PhysicalAddress	alloc();
	void	dealloc(PhysicalAddress);
private:
	std::list<MemoryRange>	memory;
	static const inline size_t	chunk_size = 0x400;
}; // class PhysicalMemory

} // namespace details

using PhysicalMemory = kfs::interface::singleton_wrapper<details::PhysicalMemory>;

} // namespace kfs

#endif // __KFS_KERNEL_SERVICE_MEMORY_PHYSICAL_MEMORY_HPP__
