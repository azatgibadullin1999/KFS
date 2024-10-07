/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paging.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:17:49 by larlena           #+#    #+#             */
/*   Updated: 2024/07/12 19:03:45 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_ARCH_X86_PAIGING_HPP__
# define __KFS_KERNEL_ARCH_X86_PAIGING_HPP__

# include <stdint.h>
# include <bitset>
# include <array>
# include "service/memory/physical_memory.hpp"

namespace kfs::x86 {

namespace experimental {

struct PageFlags {
public:
	auto	accesed() noexcept {
		return flags[5];
	}
	auto	page_cache_disable() noexcept {
		return flags[4];
	}
	auto	page_write_through() noexcept {
		return flags[3];
	}
	auto	user_supervisor() noexcept {
		return flags[2];
	}
	auto	read_write() noexcept {
		return flags[1];
	}
	auto	present() noexcept {
		return flags[0];
	}
protected:
	ktl::bitset<8>	flags [[no_unique_address]];
};

struct [[gnu::packed]] PageDirectoryFlags : public PageFlags {
	auto	page_size() noexcept {
		return flags[7];
	}
	auto	avaliable() noexcept {
		return flags[6];
	}
};

struct [[gnu::packed]] PageTableFlags : public PageFlags {
	auto	page_atribute_table() noexcept {
		return flags[7];
	}
	auto	dirty() noexcept {
		return flags[6];
	}
};

} // namespace experimental

namespace detail {

struct [[gnu::packed]] PageDirectoryFlags {
	uint8_t	present:1;
	uint8_t	read_write:1;
	uint8_t	user_supervisor:1;
	uint8_t	page_write_through:1;
	uint8_t	page_cache_disable:1;
	uint8_t	accesed:1;
	uint8_t	avaliable:1;
	uint8_t	page_size:1;
};

struct [[gnu::packed]] PageTableFlags {
	uint8_t	present:1;
	uint8_t	read_write:1;
	uint8_t	user_supervisor:1;
	uint8_t	page_write_through:1;
	uint8_t	page_cache_disable:1;
	uint8_t	accesed:1;
	uint8_t	dirty:1;
	uint8_t	page_atribute_table:1;
};

struct [[gnu::packed]] PageDirectory4KBEntry {
	PageDirectoryFlags	flags;
	uint8_t			avaliable:4;
	uint8_t			base_low:4;
	uint16_t		base_high;
};

struct [[gnu::packed]] PageTableEntry {
	PageTableFlags	flags;
	uint8_t		global:1;
	uint8_t		avaliable:3;
	uint8_t		base_low:4;
	uint16_t	base_high;
};

const inline uint32_t	address_mask = 0xFFFFF000;

} // namespace detail

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

class [[gnu::packed]] PageTableEntry : public detail::PageTableEntry {
public:
	void	setPhysicalAddress(PhysicalAddress address) noexcept {
		base_low = address >> 12;
		base_high = address >> 16;
	}

	PhysicalAddress	getPhysicalAddress() const noexcept {
		return base_high << 16 | base_low << 12;
	}

	void	setPresent() noexcept { flags.present = true; }
	void	unsetPresent() noexcept { flags.present = false; }
	bool	isPresent() noexcept { return flags.present; }

	operator uint32_t() noexcept {
		return *reinterpret_cast<uint32_t *>(this);
	}
}; // class PageTableEntry

class [[gnu::packed]] PageDirectoryEntry : public detail::PageDirectory4KBEntry {
public:
	void	setPhysicalAddress(PhysicalAddress address) noexcept {
		base_low = address >> 12;
		base_high = address >> 16;
	}

	PhysicalAddress	getPhysicalAddress() const noexcept {
		return base_high << 16 | base_low << 12;
	}

	void	setPresent() noexcept { flags.present = true; }
	void	unsetPresent() noexcept { flags.present = false; }
	bool	isPresent() noexcept { return flags.present; }

	operator uint32_t() noexcept {
		return *reinterpret_cast<uint32_t *>(this);
	}
}; // class PageDirectoryEntry

using PageUnit = ktl::array<uint32_t, 0x400>;

using Page = ktl::array<uint8_t, 0x1000>;

using PageDirectory = ktl::array<PageDirectoryEntry, 0x400>;

using PageTable = ktl::array<PageTableEntry, 0x400>;

// template <typename PageElement>
// class PagePointer {
// public:
// 	PagePointer(PageElement* ptr, PhysicalAddress addr)
// 	: pointer(ptr),
// 	  address(addr) { }

// 	PageElement&	operator * () noexcept {
// 		return *pointer;
// 	}

// 	PageElement*	operator -> () noexcept {
// 		return pointer;
// 	}



// private:
// 	PageElement	*pointer;
// 	PhysicalAddress	address;
// };

struct PageDirectoryPointer {
	PageDirectory	*pointer;
	PhysicalAddress	address;
}; // struct PageDirectoryPointer

struct PageTablePointer {
	PageTable	*pointer;
	PhysicalAddress	address;
}; // struct PageTablePointer

} // namespace kfs::x86

#endif // __KFS_KERNEL_ARCH_X86_PAIGING_HPP__
