/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_manager.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:48:22 by larlena           #+#    #+#             */
/*   Updated: 2024/10/09 12:41:03 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_PAGE_MANAGER_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_PAGE_MANAGER_HPP__

# include "arch/paging.hpp"
# include <__map/map.hpp>
# include <algorithm>
# include <ranges>
# include <span>

namespace kfs {

class PageManager {
public:
	PageManager(const kfs::x86::PageTablePointer& initialPage)
	: mPageTableMap({std::make_pair(initialPage.address, initialPage.pointer)}),
	  mFreePages(std::ranges::distance(*initialPage.pointer | std::views::filter([](auto&& tableEntry) { return tableEntry.isPresent(); }))) { }

	int	map(kfs::x86::PageDirectory &directory, const kfs::x86::VirtualAddress addr);
private:
	using TableWithDirectory = std::pair<kfs::x86::PageDirectoryEntry*, kfs::x86::PageTableEntry*>;

	template <typename range>
	auto	findFirstFreePages(kfs::x86::PageDirectory&, range&);
	int	allocatePageTable(kfs::x86::PageDirectory&, const kfs::x86::VirtualAddress);
	int	registerPageTable(kfs::x86::PageDirectoryEntry&, kfs::x86::PageTableEntry&, const kfs::x86::VirtualAddress);
	std::map<PhysicalAddress, kfs::x86::PageTable*>	mPageTableMap;
	size_t	mFreePages;
}; // class PageManager

} // namespace kfs

#endif // __KFS_KERNEL_SERVICE_MEMORY_PAGE_MANAGER_HPP__
