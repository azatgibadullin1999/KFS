/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address_space.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:19:30 by larlena           #+#    #+#             */
/*   Updated: 2025/09/29 00:08:43 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_ADDRESS_SPACE_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_ADDRESS_SPACE_HPP__

# include <span>

# include <arch/kerneldef.h>
# include <service/memory/paging.hpp>

namespace kfs {

struct AddressSpace {
	AddressSpace(page::Page::MemoryMapping page_directory);

	void load() noexcept;

	virt_addr_t allocate();
	void deallocate(virt_addr_t);

protected:
	std::span<page::Table> get_page_tables() noexcept;
	page::Directory &get_page_directory() noexcept;
	phys_addr_t get_page_directory_physical_address() noexcept;
private:
	page::Page::MemoryMapping _page_directory;
};

}

#endif // __KFS_KERNEL_SERVICE_MEMORY_ADDRESS_SPACE_HPP__
