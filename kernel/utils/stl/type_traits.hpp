/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 22:30:58 by larlena           #+#    #+#             */
/*   Updated: 2024/05/27 20:16:45 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_UTILS_STL_TYPE_TRAITS_HPP__
# define __KFS_KERNEL_UTILS_STL_TYPE_TRAITS_HPP__

# include <stddef.h>

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

template <class Type>
struct add_rvalue_reference {
	typedef Type	&&type;
};

template <class Type>
struct add_rvalue_reference<Type&> {
	typedef Type	&&type;
};

template <class Type>
struct add_rvalue_reference<Type&&> {
	typedef Type	&&type;
};

// Primary template.
/// Define a member typedef `type` only if a boolean constant is true.
template<bool, typename Tp = void>
struct enable_if { };

// Partial specialization for true.
template<typename Tp>
struct enable_if<true, Tp> {
	using type = Tp;
};

// template <typename Tp, typename... Args>
// struct __is_nt_constructible_impl : public integral_constant<bool, noexcept(Tp(declval<Args>()...))> { };

// template <typename Tp, typename Arg>
// struct __is_nt_constructible_impl<Tp, Arg> : public integral_constant<bool, noexcept(static_cast<Tp>(declval<Arg>()))> { };
 
// template <typename Tp>
// struct __is_nt_constructible_impl<Tp> : public is_nothrow_default_constructible<Tp> { };

// template <typename Tp>
// struct is_nothrow_default_constructible : __is_nt_constructible_impl<Tp> { };

template <typename T>
struct is_array : ktl::false_type {};
 
template <typename T>
struct is_array<T[]> : ktl::true_type {};
 
template <typename T, size_t N>
struct is_array<T[N]> : ktl::true_type {};

}

#endif // __KFS_KERNEL_UTILS_STL_TYPE_TRAITS_HPP__
