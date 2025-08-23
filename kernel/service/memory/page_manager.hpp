/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_manager.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:48:22 by larlena           #+#    #+#             */
/*   Updated: 2025/05/07 14:51:07 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_PAGE_MANAGER_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_PAGE_MANAGER_HPP__

#include "arch/kerneldef.h"
#include <__map/map.hpp>
#include <cstddef>
#include <ranges>
#include <__map/map.hpp>
#include "arch/paging.hpp"
#include "address_space.hpp"

namespace kfs::page {

class Manager {
public:
	Manager(const Table::Pair& pair)
	: tablesInternal{{pair}}
	, freeSize(std::ranges::distance( pair.second->getEntrys() | std::views::filter([](auto&& entry) { return entry.present; }))) { }

	int map(AddressSpace &, const VirtualAddress addr);
private:

	int map(Directory &, const PhysicalAddress, const VirtualAddress);

	template <MappingUnit Unit>
	int registerUnit(Unit directory_entry);

	std::map<PhysicalAddress, VirtualAddress>	tables;
	std::map<PhysicalAddress, VirtualAddress>	tablesInternal;
	size_t	freeSize;

}; // class Manager

} // namespace kfs

#endif // __KFS_KERNEL_SERVICE_MEMORY_PAGE_MANAGER_HPP__
