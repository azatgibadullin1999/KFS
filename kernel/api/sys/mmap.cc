/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmap.cc                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:17:49 by larlena           #+#    #+#             */
/*   Updated: 2025/09/19 19:23:14 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array>
#include <ranges>
#include <cstddef>
#include <sys/types.h>

struct Page {
	std::array<std::byte, 0x1000> entry;
};
std::array<Page, 10>	preallocated_pages;

extern "C" {

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {
	static std::array<bool, 10uz> used;

	for (auto &&index : std::views::iota(0uz, 10uz)) {
		if (!used[index]) {
			return preallocated_pages[index].entry.data();
		}
	}

	return nullptr;
}

int munmap(void *addr, size_t length) {

}

int getpagesize(void) {
	return sizeof(Page);
}

}
