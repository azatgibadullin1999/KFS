/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_range.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:19:43 by larlena           #+#    #+#             */
/*   Updated: 2024/08/28 13:30:22 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_SERVICE_MEMORY_MEMORY_RANGE_HPP__
# define __KFS_KERNEL_SERVICE_MEMORY_MEMORY_RANGE_HPP__

# include <cstddef>

namespace kfs {

using PhysicalAddress = size_t;

namespace details {

struct MemoryRange {
	PhysicalAddress	begin;
	PhysicalAddress end;
	bool	adjacent(const MemoryRange& memRange) const noexcept;
	void	merge(const MemoryRange& memRange) noexcept;
};

} // namespace details
} // namespace kfs

bool	operator == (const kfs::details::MemoryRange& lhs, const kfs::details::MemoryRange& rhs);
bool	operator != (const kfs::details::MemoryRange& lhs, const kfs::details::MemoryRange& rhs);
bool	operator < (const kfs::details::MemoryRange& lhs, const kfs::details::MemoryRange& rhs);
bool	operator > (const kfs::details::MemoryRange& lhs, const kfs::details::MemoryRange& rhs);
bool	operator >= (const kfs::details::MemoryRange& lhs, const kfs::details::MemoryRange& rhs);
bool	operator <= (const kfs::details::MemoryRange& lhs, const kfs::details::MemoryRange& rhs);

#endif // __KFS_KERNEL_SERVICE_MEMORY_MEMORY_RANGE_HPP__