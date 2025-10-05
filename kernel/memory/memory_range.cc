/**
 * @file memory_range.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <algorithm>

#include "memory_range.hpp"

namespace kfs {

bool	valid(const MemoryRange& range) noexcept {
	return std::cmp_less(range.begin, range.end);
}

bool	adjacent(const MemoryRange& lhs, const MemoryRange& rhs) noexcept {
	return     std::cmp_equal(lhs.end, rhs.begin)
		or std::cmp_equal(lhs.begin, rhs.end);
}

MemoryRange	merge(const MemoryRange& lhs, const MemoryRange& rhs) noexcept {
	MemoryRange	result;
	if (adjacent(lhs, rhs)) {
		result.begin = std::min(lhs.begin, rhs.begin);
		result.end   = std::max(lhs.end, rhs.end);
	}
	return result; 
}

MemoryRange	intersec(const MemoryRange& lhs, const MemoryRange& rhs) noexcept {
	MemoryRange	result;
	result.begin = std::max(lhs.begin, rhs.begin);
	result.end   = std::min(lhs.end, rhs.end);
	return result;
}

bool	intersected(const MemoryRange& lhs, const MemoryRange& rhs) noexcept {
	auto	tmp = intersec(lhs, rhs);
	return valid(tmp);
}

std::pair<MemoryRange, MemoryRange>	exclude(const MemoryRange& mem_range, const MemoryRange& exclude) noexcept {
	std::pair<MemoryRange, MemoryRange>	result = {{0, 0}, {0, 0}};

	if (mem_range.begin < exclude.begin) {
		result.first.begin = mem_range.begin;
		result.first.end = exclude.begin;
	}
	if (mem_range.end > exclude.end) {
		result.second.begin = exclude.end;
		result.second.end = mem_range.end;
	}
	return result;
}

} // namespace kfs::details
