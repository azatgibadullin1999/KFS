/**
 * @file mmap.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <array>
#include <ranges>
#include <cstddef>
#include <sys/types.h>


struct Page {
	std::array<std::byte, 0x1000> entry;
};
std::array<Page, 25>	g_preallocated_pages;

extern "C" {

void *mmap(void */* addr */, size_t length, int /* prot */, int /* flags */, int /* fd */, off_t /* offset */) {
	static std::array<bool, 10zu> used;
	std::size_t contiguous = 0;

	for (auto &&index : std::views::iota(0zu, 10zu)) {
		if (!used[index]) {
			if (length / sizeof(Page) < contiguous) {
				contiguous++;
			}
			used[index] = true;
			return g_preallocated_pages[index].entry.data();
		}
		contiguous = 0;
	}

	return nullptr;
}

int munmap(void */* addr */, size_t /* length */) {
	return 0;
}

int getpagesize(void) {
	return sizeof(Page);
}

}
