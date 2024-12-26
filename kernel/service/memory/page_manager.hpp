/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_manager.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:48:22 by larlena           #+#    #+#             */
/*   Updated: 2024/12/24 10:44:51 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_PAGE_MANAGER_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_PAGE_MANAGER_HPP__

# include "arch/paging.hpp"
# include "arch/kerneldef.h"
# include <__map/map.hpp>
# include <algorithm>
# include <ranges>
# include <span>
# include "physical_memory.hpp"

namespace kfs {

class VirtualAddress {
public:
	VirtualAddress(void *virtual_address)
	: mVirtualAddress(virtual_address) { }
	
	VirtualAddress(size_t directory_index, size_t table_index)
	: mVirtualAddress(reinterpret_cast<void*>(directory_index << 22 | table_index << 12 ) ) { }

	size_t	getDirectoryIndex() const noexcept {
		return reinterpret_cast<size_t>(mVirtualAddress) >> 22;
	}

	size_t	getTableIndex() const noexcept {
		return reinterpret_cast<size_t>(mVirtualAddress) >> 12 & 0x3FF;
	}

	void	*get() const noexcept {
		return mVirtualAddress;
	}
private:
	void	*mVirtualAddress;
}; // class VirtualAddress

class PageManager {
public:
	enum class AllocationType {
		DefaultAlloc,
		PhysicalMapping,
		DMARegion
	};
	PageManager(const kfs::x86::PageTablePointer& initialPage)
	: mPageTableMap({std::make_pair(initialPage.address, initialPage.pointer)}),
	  mFreePages(std::ranges::distance(*initialPage.pointer | std::views::filter([](auto&& tableEntry) { return tableEntry.isPresent(); }))) { }

	int	map(kfs::x86::PageDirectory &directory, const kfs::VirtualAddress addr, enum AllocationType type);
private:

	using TableWithDirectory = std::pair<kfs::x86::PageDirectoryEntry*, kfs::x86::PageTableEntry*>;
	int	map(kfs::x86::PageDirectory &directory, const PhysicalAddress physAddr, const kfs::VirtualAddress virtAddr);

	template <typename range>
	auto	findFirstFreePages(kfs::x86::PageDirectory&, range&);
	int	allocatePageTable(kfs::x86::PageDirectory&, const kfs::VirtualAddress);
	int	registerPageTable(kfs::x86::PageDirectoryEntry&, kfs::x86::PageTableEntry&, const kfs::VirtualAddress);
	std::map<PhysicalAddress, kfs::x86::PageTable*>	mPageTableMap;
	size_t	mFreePages;

}; // class PageManager

} // namespace kfs

#endif // __KFS_KERNEL_SERVICE_MEMORY_PAGE_MANAGER_HPP__
