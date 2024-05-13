/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:30:58 by larlena           #+#    #+#             */
/*   Updated: 2024/05/04 15:03:48 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_UTILS_STL_TYPE_TRAITS_HPP__
# define __KFS_KERNEL_UTILS_STL_TYPE_TRAITS_HPP__

namespace ktl {

/// integral_constant
template<typename Type, Type Value>
struct integral_constant {
	static constexpr Type value = Value;
	using value_type = Type;
	using type = integral_constant<Type, value>;
	constexpr operator value_type() const noexcept {
		return value;
	}
};

/// bool_constant for C++11
template<bool value>
using __bool_constant = integral_constant<bool, value>;

/// The type used as a compile-time boolean with true value.
using true_type =  __bool_constant<true>;

/// The type used as a compile-time boolean with false value.
using false_type = __bool_constant<false>;

/// is_lvalue_reference
template<typename>
struct is_lvalue_reference : public false_type { };

template<typename Type>
struct is_lvalue_reference<Type&> : public true_type { };

// Reference transformations.
/// remove_reference
template<typename Type>
struct remove_reference {
	typedef Type   type;
};

template<typename Type>
struct remove_reference<Type&> {
	typedef Type   type;
};

template<typename Type>
struct remove_reference<Type&&> {
	typedef Type   type;
};

// Primary template.
/// Define a member typedef `type` only if a boolean constant is true.
template<bool, typename _Tp = void>
struct enable_if { };

// Partial specialization for true.
template<typename _Tp>
struct enable_if<true, _Tp> {
	using type = _Tp;
};

}

#endif // __KFS_KERNEL_UTILS_STL_TYPE_TRAITS_HPP__
