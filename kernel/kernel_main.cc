/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel_main.cc                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:46:12 by larlena           #+#    #+#             */
/*   Updated: 2025/09/27 18:41:10 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "multiboot.h"
#include "kernel.hpp"
#include <elf.h>

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
	auto&&	kernel = kfs::Kernel::init(mbd);

	kernel.start();
}
