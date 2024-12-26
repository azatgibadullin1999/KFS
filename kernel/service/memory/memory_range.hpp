/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_range.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:19:43 by larlena           #+#    #+#             */
/*   Updated: 2024/12/26 11:47:24 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_MEMORY_RANGE_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_MEMORY_RANGE_HPP__

# include <cstddef>
# include <__utility/pair.h>
# include "ktypedef.h"

namespace kfs {

struct MemoryRange {
	addr_t	begin;
	addr_t	end;
};

bool		valid(const MemoryRange& range) noexcept;
bool		adjacent(const MemoryRange& lhsRange, const MemoryRange& rhsRange) noexcept;
MemoryRange	merge(const MemoryRange& lhsRange, const MemoryRange& rhsRange) noexcept;
MemoryRange	intersec(const MemoryRange& lhsRange, const MemoryRange& rhsRange) noexcept;	
bool		intersected(const MemoryRange& lhsRange, const MemoryRange& rhsRange) noexcept;
std::pair<MemoryRange, MemoryRange>	exclude(const MemoryRange& memRange, const MemoryRange& exclude) noexcept;

} // namespace kfs

bool	operator == (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs);
bool	operator != (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs);
bool	operator < (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs);
bool	operator > (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs);
bool	operator >= (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs);
bool	operator <= (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs);

#endif // __KFS_KERNEL_SERVICE_MEMORY_MEMORY_RANGE_HPP__