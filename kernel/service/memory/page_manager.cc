/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_manager.cc                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 22:15:30 by larlena           #+#    #+#             */
/*   Updated: 2024/12/23 20:57:15 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "page_manager.hpp"
#include "physical_memory.hpp"

int	kfs::PageManager::map(kfs::x86::PageDirectory& directory, const kfs::x86::VirtualAddress addr) {
	auto&&	directoryEntry = directory[addr.getDirectoryIndex()];

	if (!directoryEntry.isPresent()) {
		allocatePageTable(directory, addr);
	}

	auto&&	tableEntry = (*mPageTableMap[directoryEntry.getPhysicalAddress()])[addr.getTableIndex()];
	if (tableEntry.isPresent()) {
		return 1;
	}
	tableEntry.setPhysicalAddress(kfs::PhysicalMemorySingleton::getInstance().alloc());
}

template <typename range>
auto	kfs::PageManager::findFirstFreePages(kfs::x86::PageDirectory& directory, range& outRange) {
	auto&&	existingPageDirectoryEntrys = directory
		| std::views::filter([](auto&& directoryEntry){ return directoryEntry.isPresent(); });
	auto&&	freePageTableEntrys = std::views::transform([this](auto&& directoryEntry) {
			return *this->mPageTableMap[directoryEntry.getPhysicalAddress()];
		})
		| std::views::join
		| std::views::filter([](auto &&tableEntry) { return !tableEntry.isPresent(); });
	auto&&	outIt = outRange.begin();

	for (auto&& directoryEntry : existingPageDirectoryEntrys) {
		outIt->first = std::addressof(directoryEntry);
		for (auto&& tableEntry :  std::views::single(directoryEntry) | freePageTableEntrys) {
			outIt->second = std::addressof(tableEntry);
			++outIt;
			if (outIt == outRange.end()) {
				return outIt;
			}
		}
	}
	return outIt;
}


int	kfs::PageManager::allocatePageTable(kfs::x86::PageDirectory& directory, const kfs::x86::VirtualAddress addr) {
	auto&&	freePages = ktl::array<TableWithDirectory, 4>();
	auto&&	page = freePages.begin();

	if (std::distance(freePages.begin(), findFirstFreePages(directory, freePages)) == 3) {
		auto&&	emptyDirectoryEntry = *std::ranges::find(directory, false, [](auto&& directoryEntry) { return directoryEntry.isPresent(); });
		registerPageTable(emptyDirectoryEntry, *page->second, addr);
		++page;
	}
	registerPageTable(*page->first, *page->second, addr);
}

int	kfs::PageManager::registerPageTable(kfs::x86::PageDirectoryEntry& directoryEntry, kfs::x86::PageTableEntry& freeTableEntry, const kfs::x86::VirtualAddress addr) {
	auto&&	physicalAddress = kfs::PhysicalMemorySingleton::getInstance().alloc();

	freeTableEntry.setPhysicalAddress(physicalAddress);
	freeTableEntry.setPresent();

	auto&&	newPageTable = std::construct_at(reinterpret_cast<kfs::x86::PageTable *>(addr.get()));
	auto&&	result = mPageTableMap.emplace(physicalAddress, newPageTable);

	directoryEntry.setPhysicalAddress(result.first->first);
}

