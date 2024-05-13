/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_resource.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 22:39:20 by larlena           #+#    #+#             */
/*   Updated: 2024/05/27 13:49:44 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_UTILS_STL_ALLOCATOR_HPP__
# define __KFS_KERNEL_UTILS_STL_ALLOCATOR_HPP__

# include <stddef.h>

namespace ktl::pmr {

class memory_resource {
public:
	[[nodiscard]] void	*allocate(size_t bytes, size_t alignment = alignof(max_align_t)) {
		return do_allocate(bytes, alignment);
	}

	void	allocate(void *p, size_t bytes, size_t alignment = alignof(max_align_t)) {
		do_deallocate(p, bytes, alignment);
	}

	bool	is_equal(const memory_resource &other) const noexcept {
		return do_is_equal(other);
	}
protected:
	virtual void	*do_allocate(size_t bytes, size_t alignment = alignof(max_align_t)) = 0;

	virtual void	do_deallocate(void *p, size_t bytes, size_t alignment = alignof(max_align_t)) = 0;

	virtual bool	do_is_equal(const memory_resource &other) const noexcept = 0;
};

template <typename T>
class polymorphic_allocator {
public:
	using value_type = T;
	using size_type = size_t;
	using difference_type = ptrdiff_t;

	polymorphic_allocator() noexcept { }

	polymorphic_allocator(const polymorphic_allocator &other) = default;

	template <typename U>
	constexpr polymorphic_allocator(const polymorphic_allocator<U> &other) noexcept { }

	constexpr ~polymorphic_allocator() { }

	[[nodiscard]] constexpr value_type*	allocate(size_type n);

	constexpr void	deallocate(value_type *ptr, size_type n);
};




} // namespace ktl

bool	operator == (const ktl::pmr::memory_resource &lhs, const ktl::pmr::memory_resource &rhs) {
	return &lhs == &rhs || lhs.is_equal(rhs);
}

bool	operator != (const ktl::pmr::memory_resource &lhs, const ktl::pmr::memory_resource &rhs) {
	return !(lhs == rhs);
}

#endif // __KFS_KERNEL_UTILS_STL_ALLOCATOR_HPP__
