/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_range.cc                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:21:31 by larlena           #+#    #+#             */
/*   Updated: 2024/12/26 11:47:16 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory_range.hpp"
#include <algorithm>

namespace kfs {

bool	valid(const MemoryRange& range) noexcept {
	return range.begin < range.end;
}

bool	adjacent(const MemoryRange& lhsRange, const MemoryRange& rhsRange) noexcept {
	return lhsRange.end == rhsRange.begin || lhsRange.begin == rhsRange.end;
}

MemoryRange	merge(const MemoryRange& lhsRange, const MemoryRange& rhsRange) noexcept {
	MemoryRange	result;
	if (adjacent(lhsRange, rhsRange)) {
		result.begin = std::min(lhsRange.begin, rhsRange.begin);
		result.end = std::max(lhsRange.end, rhsRange.end);
	}
	return result; 
}

MemoryRange	intersec(const MemoryRange& lhsRange, const MemoryRange& rhsRange) noexcept {
	MemoryRange	result;
	result.begin = std::max(lhsRange.begin, rhsRange.begin);
	result.end = std::min(lhsRange.end, rhsRange.end);
	return result;
}

bool	intersected(const MemoryRange& lhsRange, const MemoryRange& rhsRange) noexcept {
	auto	tmp = intersec(lhsRange, rhsRange);
	return valid(tmp);
}

std::pair<MemoryRange, MemoryRange>	exclude(const MemoryRange& memRange, const MemoryRange& exclude) noexcept {
	std::pair<MemoryRange, MemoryRange>	resultRanges = {{0, 0}, {0, 0}};

	if (memRange.begin < exclude.begin) {
		resultRanges.first.begin = memRange.begin;
		resultRanges.first.end = exclude.begin;
	}
	if (memRange.end > exclude.end) {
		resultRanges.second.begin = exclude.end;
		resultRanges.second.end = memRange.end;
	}
	return resultRanges;
}

} // namespace kfs::details

bool	operator == (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs) {
	return lhs.begin == rhs.begin && lhs.end == rhs.end;
}
bool	operator != (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs) {
	return !(lhs == rhs);
}
bool	operator < (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs) {
	return lhs.begin < rhs.begin && lhs.end < rhs.end;
}
bool	operator > (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs) {
	return lhs.begin > rhs.begin && lhs.end > rhs.end;
}
bool	operator >= (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs) {
	return !(lhs < rhs);
}
bool	operator <= (const kfs::MemoryRange& lhs, const kfs::MemoryRange& rhs) {
	return !(lhs > rhs);
}
