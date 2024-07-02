/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:32:58 by larlena           #+#    #+#             */
/*   Updated: 2024/05/12 11:01:55 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_UTILS_STL_MOVE_HPP__
# define __KFS_KERNEL_UTILS_STL_MOVE_HPP__

# include "type_traits.hpp"

namespace ktl {

template <typename Type>
constexpr typename ktl::remove_reference<Type>::type&&	move(Type&& value) noexcept {
	return static_cast<typename ktl::remove_reference<Type>::type&&>(value);
}

/// Forward lvalues as rvalues.
template <typename Type>
inline typename enable_if<!is_lvalue_reference<Type>::value, Type&&>::type	forward(typename ktl::remove_reference<Type>::type& value) {
	return static_cast<Type&&>(value);
}

/// Forward rvalues as rvalues.
template <typename Type>
inline typename enable_if<!is_lvalue_reference<Type>::value, Type&&>::type	forward(typename ktl::remove_reference<Type>::type&& value) {
	return static_cast<Type&&>(value);
}

// Forward lvalues as lvalues.
template <typename Type>
inline typename enable_if<is_lvalue_reference<Type>::value, Type>::type	forward(typename ktl::remove_reference<Type>::type value) {
	return value;
}

// Prevent forwarding rvalues as const lvalues.
template <typename Type>
inline typename enable_if<is_lvalue_reference<Type>::value, Type>::type	forward(typename ktl::remove_reference<Type>::type&& value) = delete;

template <typename Type>
inline void	swap(Type &a, Type &b) noexcept {
	Type	tmp = ktl::move(a);
	a = ktl::move(b);
	b = ktl::move(tmp);
}

}

#endif // __KFS_KERNEL_UTILS_STL_MOVE_HPP__
