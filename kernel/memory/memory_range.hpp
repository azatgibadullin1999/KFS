/**
 * @file memory_range.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef KFS_KERNEL_SERVICE_MEMORY_MEMORY_RANGE_HPP
# define KFS_KERNEL_SERVICE_MEMORY_MEMORY_RANGE_HPP

# include <cstddef>
# include <utility>

# include <kfs/memory.hpp>

namespace kfs {

struct MemoryRange {
	kfs::phys_addr_t	begin;
	kfs::phys_addr_t	end;
};

bool		valid(const MemoryRange& range) noexcept;
bool		adjacent(const MemoryRange& lhs, const MemoryRange& rhs) noexcept;
MemoryRange	merge(const MemoryRange& lhs, const MemoryRange& rhs) noexcept;
MemoryRange	intersec(const MemoryRange& lhs, const MemoryRange& rhs) noexcept;	
bool		intersected(const MemoryRange& lhs, const MemoryRange& rhs) noexcept;
std::pair<MemoryRange, MemoryRange>	exclude(const MemoryRange& mem_range, const MemoryRange& exclude) noexcept;

} // namespace kfs

static inline bool operator == (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs) { return lhs.begin == rhs.begin && lhs.end == rhs.end; }
static inline bool operator != (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs) { return !(lhs == rhs); }
static inline bool operator <  (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs) { return lhs.begin < rhs.begin && lhs.end < rhs.end; }
static inline bool operator >  (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs) { return lhs.begin > rhs.begin && lhs.end > rhs.end; }
static inline bool operator >= (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs) { return !(lhs < rhs); }
static inline bool operator <= (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs) { return !(lhs > rhs); }

#endif // KFS_KERNEL_SERVICE_MEMORY_MEMORY_RANGE_HPP