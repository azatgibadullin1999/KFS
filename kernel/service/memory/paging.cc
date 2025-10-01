/**
 * @file paging.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 29-09-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "paging.hpp"
#include <arch/kerneldef.h>

namespace {

void invaledate_page(virt_addr_t address) noexcept {
	asm volatile (
	"invlpg (%0)\n\t"
		:
		: "r"(address)
		: "memory");
}

}

kfs::page::Table::Entry::Setter::~Setter() {
	if (_address)
		invaledate_page(_address);
}

kfs::page::Directory::Entry::Setter::~Setter() {
	if (_address)
		invaledate_page(_address);
}
