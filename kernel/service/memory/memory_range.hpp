/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_range.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:19:43 by larlena           #+#    #+#             */
/*   Updated: 2025/09/13 23:30:09 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_MEMORY_RANGE_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_MEMORY_RANGE_HPP__

# include <cstddef>
# include <utility>

# include "kerneldef.h"

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