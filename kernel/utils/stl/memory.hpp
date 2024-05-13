/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:53:47 by larlena           #+#    #+#             */
/*   Updated: 2024/05/27 14:53:52 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_UTILS_STL_MEMORY_HPP__
# define __KFS_KERNEL_UTILS_STL_MEMORY_HPP__

# include <stddef.h>
# include "move.hpp"
# include "type_traits.hpp"

namespace ktl {

template <typename T, typename ... Args>
constexpr T*	construct_at(T* p, Args&& ... args) {
	return return ::new (static_cast<void*>(p)) T(ktl::forward<Args>(args)...);
}

template <class T>
constexpr void	destroy_at(T* p) {
	p->~T();
}

// template <typename Ptr>
// struct pointer_traits {
// public:
// 	using pointer = Ptr;
// 	using element_type = ktl::remove_reference<Ptr>::type;
// 	using difference_type = ptrdiff_t

// 	template <typename U>
// 	using rebound = U*;

// 	static pointer	pointer_to(element_type& r) {
// 		return &r;
// 	}

// 	static constexpr pointer	pointer_to(element_type &r) noexcept {
// 		return &r;
// 	}
// };

// template <typename T>
// struct pointer_traits<T*> {
// public:
// 	using pointer = T*;
// 	using element_type = T;
// 	using difference_type = ptrdiff_t

// 	template <typename U>
// 	using rebound = U*;

// 	static pointer	pointer_to(element_type& r) {
// 		return &r;
// 	}

// 	static constexpr pointer	pointer_to(element_type &r) noexcept {
// 		return &r;
// 	}
// };

// template <typename Alloc>
// class allocator_traits {
// public:
// 	using allocator_type = Alloc;
// 	using value_type = allocator_type::value_type;
// 	using pointer = value_type*;
// 	using const_pointer = pointer_traits<pointer>::rebind<const value_type>;
// 	using void_pointer = pointer_traits<pointer>::rebind<void>;
// 	using const_void_pointer = pointer_traits<pointer>::rebind<const void>;
// 	using difference_type = ptrdiff_t;
// 	using size_type = size_t;
// 	using propagate_on_container_copy_assignment = ktl::false_type;
// 	using propagate_on_container_move_assignment = ktl::false_type;
// 	using propagate_on_container_swap = ktl::false_type;

// 	[[nodiscard]] static constexpr pointer	allocate(allocator_type& allocator, size_type n) {
// 		return allocator.allocate(n * sizeof(value_type));
// 	}
// 	[[nodiscard]] static constexpr pointer	allocate(allocator_type& allocator, size_type n, const_void_pointer hint) {
// 		return allocator.allocate(n * sizeof(value_type), hint);
// 	}

// 	static constexpr void	deallocate(allocator_type& allocator, pointer p, size_type n) {
// 		allocator.deallocate(p, n);
// 	}

// 	template <typename T, typename ... Args>
// 	static constexpr void	construct(allocator_type& allocator, T* p, Args&&... args);
// 	template <typename T>
// 	static constexpr void	destroy(allocator_type& allocator, T* p);
// 	static constexpr size_type	max_size(const allocator_type& allocator) noexcept;
	
// };

}

#endif // __KFS_KERNEL_UTILS_STL_MEMORY_HPP__
