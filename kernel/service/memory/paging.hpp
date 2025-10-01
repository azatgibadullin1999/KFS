/**
 * @file paging.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_PAIGING_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_PAIGING_HPP__

#include <bitset>
#include <span>
#include <array>
#include <cstdint>
#include <cstddef>
#include <utility>

#include "arch/kerneldef.h"

namespace kfs::page {

struct Page {
	struct MemoryMapping {
		Page*       virtual_address;
		phys_addr_t physical_address;
	};

	std::array<std::byte, 0x1000> data;
};
static_assert(sizeof(Page) == 0x1000, "");

constexpr std::size_t page_size = sizeof(Page);
constexpr std::size_t page_mask = ~(sizeof(Page) - 1);

namespace detail {
struct DirectoryEntry {
	uint8_t	 present:1;
	uint8_t	 read_write:1;
	uint8_t	 user_supervisor:1;
	uint8_t	 page_write_through:1;
	uint8_t	 page_cache_disable:1;
	uint8_t	 accesed:1;
	uint8_t	 dirty:1;
	uint8_t	 page_atribute_table:1;
	uint8_t  kfs_full:1;
	uint8_t	 avaliable:3;
	uint8_t	 base_low:4;
	uint16_t base_high;
};
}

struct Directory : private Page {
	struct Entry : private detail::DirectoryEntry {
		struct Setter {
			Setter(detail::DirectoryEntry &entry, virt_addr_t address)
			: _entry{ entry }, _address{ address } { }
			~Setter();
			Setter&& present(bool val) && noexcept              { _entry.present = val;             return std::move(*this); }
			Setter&& read_write(bool val) && noexcept           { _entry.read_write = val;          return std::move(*this); }
			Setter&& user_supervisor(bool val) && noexcept      { _entry.user_supervisor = val;     return std::move(*this); }
			Setter&& page_write_through(bool val) && noexcept   { _entry.page_write_through = val;  return std::move(*this); }
			Setter&& page_cache_disable(bool val) && noexcept   { _entry.page_cache_disable = val;  return std::move(*this); }
			Setter&& accesed(bool val) && noexcept              { _entry.accesed = val;             return std::move(*this); }
			Setter&& dirty(bool val) && noexcept                { _entry.dirty = val;               return std::move(*this); }
			Setter&& page_atribute_table(bool val) && noexcept  { _entry.page_atribute_table = val; return std::move(*this); }
			Setter&& kfs_full(bool val) && noexcept             { _entry.kfs_full = val;            return std::move(*this); }
			Setter&& phys_addr(phys_addr_t address) && noexcept {
				_entry.base_low = address >> 12;
				_entry.base_high = address >> 16;
				return std::move(*this);
			};
		private:
			detail::DirectoryEntry &_entry;
			virt_addr_t _address;
		};
		bool   is_present() const noexcept             { return present;             }
		bool   is_read_write() const noexcept          { return read_write;          }
		bool   is_user_supervisor() const noexcept     { return user_supervisor;     }
		bool   is_page_write_through() const noexcept  { return page_write_through;  }
		bool   is_page_cache_disable() const noexcept  { return page_cache_disable;  }
		bool   is_accesed() const noexcept             { return accesed;             }
		bool   is_dirty() const noexcept               { return dirty;               }
		bool   is_page_atribute_table() const noexcept { return page_atribute_table; }
		bool   is_kfs_full() const noexcept            { return kfs_full;            }
		phys_addr_t get_phys_addr() const noexcept     { return base_high << 16 | base_low << 12; }
		Setter set(virt_addr_t address) { return Setter{*this, address}; }
	};

	auto entrys() {
		return std::span<Entry>{
			reinterpret_cast<Entry*>(data.begin()),
			reinterpret_cast<Entry*>(data.end())
		};
	}
};
static_assert(sizeof(Directory::Entry) == 4, "");
static_assert(sizeof(Directory) == 0x1000, "");

namespace detail {
struct TableEntry {
	uint8_t	 present:1;
	uint8_t	 read_write:1;
	uint8_t	 user_supervisor:1;
	uint8_t	 page_write_through:1;
	uint8_t	 page_cache_disable:1;
	uint8_t	 accesed:1;
	uint8_t	 dirty:1;
	uint8_t	 page_atribute_table:1;
	uint8_t	 global:1;
	uint8_t	 avaliable:3;
	uint8_t	 base_low:4;
	uint16_t base_high;
};
}
struct Table : private Page {
	struct Entry : private detail::TableEntry {
		struct Setter {
			Setter(detail::TableEntry &entry, virt_addr_t address)
			: _entry{ entry }, _address{ address } { }
			~Setter();
			Setter&& present(bool val) && noexcept              { _entry.present = val;             return std::move(*this); }
			Setter&& read_write(bool val) && noexcept           { _entry.read_write = val;          return std::move(*this); }
			Setter&& user_supervisor(bool val) && noexcept      { _entry.user_supervisor = val;     return std::move(*this); }
			Setter&& page_write_through(bool val) && noexcept   { _entry.page_write_through = val;  return std::move(*this); }
			Setter&& page_cache_disable(bool val) && noexcept   { _entry.page_cache_disable = val;  return std::move(*this); }
			Setter&& accesed(bool val) && noexcept              { _entry.accesed = val;             return std::move(*this); }
			Setter&& dirty(bool val) && noexcept                { _entry.dirty = val;               return std::move(*this); }
			Setter&& page_atribute_table(bool val) && noexcept  { _entry.page_atribute_table = val; return std::move(*this); }
			Setter&& global(bool val) && noexcept               { _entry.global = val;              return std::move(*this); }
			Setter&& phys_addr(phys_addr_t address) && noexcept {
				_entry.base_low = address >> 12;
				_entry.base_high = address >> 16;
				return std::move(*this);
			};
		private:
			detail::TableEntry &_entry;
			virt_addr_t _address;
		};
		bool   is_present() const noexcept             { return present;             }
		bool   is_read_write() const noexcept          { return read_write;          }
		bool   is_user_supervisor() const noexcept     { return user_supervisor;     }
		bool   is_page_write_through() const noexcept  { return page_write_through;  }
		bool   is_page_cache_disable() const noexcept  { return page_cache_disable;  }
		bool   is_accesed() const noexcept             { return accesed;             }
		bool   is_dirty() const noexcept               { return dirty;               }
		bool   is_page_atribute_table() const noexcept { return page_atribute_table; }
		bool   is_global() const noexcept              { return global;              }
		phys_addr_t get_phys_addr() const noexcept     { return base_high << 16 | base_low << 12; }
		Setter set(virt_addr_t address) { return Setter{*this, address}; }

	};
	auto entrys() {
		return std::span<Entry>{
			reinterpret_cast<Entry*>(data.begin()),
			reinterpret_cast<Entry*>(data.end())
		};
	}
};
static_assert(sizeof(Table::Entry) == 4, "");
static_assert(sizeof(Table) == 0x1000, "");

} // namespace kfs::page

#endif // __KFS_KERNEL_SERVICE_MEMORY_PAIGING_HPP__
