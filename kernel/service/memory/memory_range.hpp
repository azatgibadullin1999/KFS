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

#ifndef __KFS_KERNEL_SERVICE_MEMORY_MEMORY_RANGE_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_MEMORY_RANGE_HPP__

# include <cstddef>
# include <utility>

# include "arch/kerneldef.h"

namespace kfs {

struct MemoryRange {
	phys_addr_t	begin;
	phys_addr_t	end;
};

bool		valid(const MemoryRange& range) noexcept;
bool		adjacent(const MemoryRange& lhsRange, const MemoryRange& rhsRange) noexcept;
MemoryRange	merge(const MemoryRange& lhsRange, const MemoryRange& rhsRange) noexcept;
MemoryRange	intersec(const MemoryRange& lhsRange, const MemoryRange& rhsRange) noexcept;	
bool		intersected(const MemoryRange& lhsRange, const MemoryRange& rhsRange) noexcept;
std::pair<MemoryRange, MemoryRange>	exclude(const MemoryRange& memRange, const MemoryRange& exclude) noexcept;

} // namespace kfs

static inline bool operator == (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs) { return lhs.begin == rhs.begin && lhs.end == rhs.end; }
static inline bool operator != (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs) { return !(lhs == rhs); }
static inline bool operator <  (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs) { return lhs.begin < rhs.begin && lhs.end < rhs.end; }
static inline bool operator >  (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs) { return lhs.begin > rhs.begin && lhs.end > rhs.end; }
static inline bool operator >= (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs) { return !(lhs < rhs); }
static inline bool operator <= (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs) { return !(lhs > rhs); }

#endif // __KFS_KERNEL_SERVICE_MEMORY_MEMORY_RANGE_HPP__