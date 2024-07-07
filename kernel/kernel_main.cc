/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel_main.cc                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:46:12 by larlena           #+#    #+#             */
/*   Updated: 2024/06/25 15:54:03 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "../boot/multiboot.h"
#include "kernel.hpp"
#include <libft.hpp>
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

	for(size_t i = 0; i < mbd->mmap_length; 
		i += sizeof(multiboot_memory_map_t)) {
		multiboot_memory_map_t* mmmt = reinterpret_cast<multiboot_memory_map_t*>(mbd->mmap_addr + i);
 		printf("Start Addr: %x | Length: %x | Size: %x | Type: %d\n",
		mmmt->addr, mmmt->len, mmmt->size, mmmt->type);
	}

	multiboot_elf_section_header_table_t *multiboot_elf_sec = &(mbd->u.elf_sec);

	printf ("multiboot_elf_sec: num = %u, size = 0x%x,"
		" addr = 0x%x, shndx = 0x%s\n",
		(unsigned) multiboot_elf_sec->num, (unsigned) multiboot_elf_sec->size,
		(unsigned) multiboot_elf_sec->addr, (unsigned) multiboot_elf_sec->shndx);


	auto	header = reinterpret_cast<Elf32_Shdr*>(multiboot_elf_sec->addr);
	auto	header_buff = header;


	// for (size_t i = 0; i != multiboot_elf_sec->num; ++i) {
	// 	if (header[i].sh_addr + header[i].sh_offset + header[i].sh_size >
	// 	    header_buff->sh_addr + header_buff->sh_offset + header_buff->sh_size) {
	// 		header_buff = &header[i];
	// 	}
	// }

	// printf ("\n\
	// header_buff->sh_name = %x\n\
	// header_buff->sh_type = %x\n\
	// header_buff->sh_flags = %x\n\
	// header_buff->sh_addr = %x\n\
	// header_buff->sh_offset = %x\n\
	// header_buff->sh_size = %x\n\
	// header_buff->sh_link = %x\n\
	// header_buff->sh_info = %x\n\
	// header_buff->sh_addralign = %x\n\
	// header_buff->sh_entsize = %x\n\
	// name = %s\n",
	// header_buff->sh_name,
	// header_buff->sh_type,
	// header_buff->sh_flags,
	// header_buff->sh_addr,
	// header_buff->sh_offset,
	// header_buff->sh_size,
	// header_buff->sh_link,
	// header_buff->sh_info,
	// header_buff->sh_addralign,
	// header_buff->sh_entsize,
	// multiboot_elf_sec->shndx + header_buff->sh_name
	// );

	auto&&	multiboot_mmap = std::span<multiboot_memory_map_t>(
		reinterpret_cast<multiboot_memory_map_t*>(mbd->mmap_addr),
		reinterpret_cast<multiboot_memory_map_t*>(mbd->mmap_addr) + (mbd->mmap_length / sizeof(multiboot_memory_map_t))
	);
	auto&&	range = multiboot_mmap
		| std::views::transform([](auto &&mr){
			size_t address_begin = static_cast<size_t>(mr.addr);
			size_t address_end = static_cast<size_t>(mr.addr + mr.len) & ~0x3FF;

			address_begin = (address_begin & 0x3FF ? address_begin + 0x400 : address_begin) & ~0x3FF;
			address_end = address_end < address_begin ? address_end - 0x400 : address_end;
			if (address_begin < 0x400000) {
				address_begin = 0x400000;
			}
			return std::make_pair(reinterpret_cast<void*>(address_begin), reinterpret_cast<void*>(address_end));
		})
		| std::views::filter([](auto &&pair){
			return pair.first < pair.second;
		})  ;

	auto&&	elf_sh_range = std::span<Elf32_Shdr>(header, header + multiboot_elf_sec->num);
	
	// auto&&	range = multiboot_mmap
	// 	| std::views::transform([](auto&& it){
	// 		return 
	// 	})
	printf("page begin = %x\n", range.begin());
	printf("page begin = %x\n", range.end());

	// printf("page begin = %x\n", multiboot_mmap.front().addr);
	// printf("page begin = %x\n", multiboot_mmap.front().len );
	// printf("page begin = %x\n", multiboot_mmap.front().size);
	// printf("page begin = %x\n", multiboot_mmap.front().type);

	// printf("page begin = %x\n", multiboot_mmap.back().addr);
	for (auto it : range) {
		printf("begin = %x\n", it.first);
		printf("end = %x\n", it.second);
	}

	printf("done\n");

	kernel.start();
}
