/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmap.cc                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:17:49 by larlena           #+#    #+#             */
/*   Updated: 2025/09/14 00:18:49 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdint.h>
#include <bitset>
#include <algorithm>
#include <ranges>
#include <service/memory/page_manager.hpp>

std::array<uint8_t, 0x2000>	preallocated_pages;
static const size_t	size_of_page = 0x400;
static const size_t	number_of_pages = sizeof(preallocated_pages) / size_of_page;
std::bitset<sizeof(preallocated_pages) / size_of_page>  pages;

extern "C" void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {
	auto&&	indexOfFreePages = std::views::iota(0UL, number_of_pages)
		| std::views::filter([](auto&& index) {
			return !pages[index];
		});
	
	if (indexOfFreePages.begin() != indexOfFreePages.end()) {
		return reinterpret_cast<void *>(preallocated_pages[*indexOfFreePages.begin() * size_of_page]);
	}
	// return 
	return nullptr;
}

extern "C" int munmap(void *addr, size_t length) {

}

extern "C" int getpagesize(void) {
	return size_of_page;
}