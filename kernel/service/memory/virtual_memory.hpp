/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virtual_memory.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:03:35 by larlena           #+#    #+#             */
/*   Updated: 2024/06/19 16:48:09 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_VIRTUAL_MEMORY_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_VIRTUAL_MEMORY_HPP__

# include "arch/x86/paging.hpp"
# include "virtual_memory_component.hpp"
# include <array>

namespace kfs {

namespace deteils {

const static inline size_t	size_of_preallocated_pages = 0x2000;

void	*getPreallocatedPages() {
	static uint32_t	raw_pages[size_of_preallocated_pages] [[gnu::section(".bss")]] [[gnu::aligned(0x400)]];
	return raw_pages;
}

}

class VirtualMemory {
public:
	int	map(size_t virt_addr, size_t phys_addr) {
		size_t	directory_index = virt_addr >> 22;
		size_t	table_index = (virt_addr >> 12) & 0x3FF;
		auto	pageDirectory = kfs::getCurrentPageDirectory();

		
		if (!pageDirectory[directory_index].flags.present) {
			
		}
	}

};

}

#endif // __KFS_KERNEL_SERVICE_MEMORY_VIRTUAL_MEMORY_HPP__
