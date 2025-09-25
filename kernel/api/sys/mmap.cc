/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmap.cc                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:17:49 by larlena           #+#    #+#             */
/*   Updated: 2025/09/25 23:37:14 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array>
#include <ranges>
#include <cstddef>
#include <service/memory/physical_memory.hpp>
#include <sys/types.h>

struct Page {
	std::array<std::byte, 0x1000> entry;
};
std::array<Page, 25>	preallocated_pages;

extern "C" {

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {
	static std::array<bool, 10zu> used;
	std::size_t contiguous = 0;

	for (auto &&index : std::views::iota(0zu, 10zu)) {
		if (!used[index]) {
			if (length / sizeof(Page) < contiguous) {
				contiguous++;
			}
			used[index] = true;
			return preallocated_pages[index].entry.data();
		} else {
			contiguous = 0;
		}
	}

	return (void *)kfs::PhysicalMemory::instance().alloc();
}

int munmap(void *addr, size_t length) {
	return 0;
}

int getpagesize(void) {
	return sizeof(Page);
}

}
