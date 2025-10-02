/**
 * @file kernel_main.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <cstdint>

#include <kernel.hpp>

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
