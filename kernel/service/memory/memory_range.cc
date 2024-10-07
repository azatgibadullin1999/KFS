/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_range.cc                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:21:31 by larlena           #+#    #+#             */
/*   Updated: 2024/08/28 13:37:37 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_range.hpp"
#include <algorithm>

namespace kfs::details {

bool	MemoryRange::adjacent(const MemoryRange& memRange) const noexcept {
	return end == memRange.begin || begin == memRange.end;
}

void	MemoryRange::merge(const MemoryRange& memRange) noexcept {
	if (adjacent(memRange)) {
		begin = std::min(begin, memRange.begin);
		end = std::max(end, memRange.end);
	}
}

} // namespace kfs::details

bool	operator == (const kfs::details::MemoryRange& lhs, const kfs::details::MemoryRange& rhs) {
	return lhs.begin == rhs.begin && lhs.end == rhs.end;
}
bool	operator != (const kfs::details::MemoryRange& lhs, const kfs::details::MemoryRange& rhs) {
	return !(lhs == rhs);
}
bool	operator < (const kfs::details::MemoryRange& lhs, const kfs::details::MemoryRange& rhs) {
	return lhs.begin < rhs.begin && lhs.end < rhs.end;
}
bool	operator > (const kfs::details::MemoryRange& lhs, const kfs::details::MemoryRange& rhs) {
	return lhs.begin > rhs.begin && lhs.end > rhs.end;
}
bool	operator >= (const kfs::details::MemoryRange& lhs, const kfs::details::MemoryRange& rhs) {
	return !(lhs < rhs);
}
bool	operator <= (const kfs::details::MemoryRange& lhs, const kfs::details::MemoryRange& rhs) {
	return !(lhs > rhs);
}
