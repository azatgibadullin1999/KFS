/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel_main.cc                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:46:12 by larlena           #+#    #+#             */
/*   Updated: 2024/05/27 12:26:18 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "../boot/multiboot.h"
#include "kernel.hpp"
#include "utils/libft.hpp"

#if defined(__linux__)
# error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#if !defined(__i386__)
# error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

void	*stack_top;

extern "C" void kernel_main(uint32_t magic, multiboot_info_t* mbd, void *stack_top_top) {
	if (magic != MULTIBOOT_BOOTLOADER_MAGIC) {
		return ;
	}

	stack_top = stack_top_top;
	auto&&	kernel = Kernel::init(mbd);

	for(size_t i = 0; i < mbd->mmap_length; 
		i += sizeof(multiboot_memory_map_t)) {
		multiboot_memory_map_t* mmmt = reinterpret_cast<multiboot_memory_map_t*>(mbd->mmap_addr + i);
 		kfs::printf("Start Addr: %x | Length: %x | Size: %x | Type: %d\n",
		mmmt->addr, mmmt->len, mmmt->size, mmmt->type);
	}

	// kernel.start();
}
