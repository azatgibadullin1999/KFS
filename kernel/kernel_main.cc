/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel_main.cc                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:46:12 by larlena           #+#    #+#             */
/*   Updated: 2024/12/23 20:23:20 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "../boot/multiboot.h"
#include "kernel.hpp"
#include <string.h>
#include <stdio.h>
#include <elf.h>

#include <span>
#include <algorithm>
#include <ranges>
#include "service/memory/physical_memory.hpp"

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

	kernel.start();
}
