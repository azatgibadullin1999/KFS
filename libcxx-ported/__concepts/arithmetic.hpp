/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:56:49 by larlena           #+#    #+#             */
/*   Updated: 2024/05/31 19:31:30 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___CONCEPTS_ARITHMETIC_HPP__
# define __KFS_OWN_LIBCXX___CONCEPTS_ARITHMETIC_HPP__

#include <__type_traits/is_floating_point.hpp>
#include <__type_traits/is_integral.hpp>
#include <__type_traits/is_signed.hpp>
#include <__type_traits/is_signed_integer.hpp>
#include <__type_traits/is_unsigned_integer.hpp>


namespace std {

// [concepts.arithmetic], arithmetic concepts

template <class _Tp>
concept integral =
	is_integral_v<_Tp>;

template <class _Tp>
concept signed_integral =
	integral<_Tp> &&
	is_signed_v<_Tp>;

template <class _Tp>
concept unsigned_integral =
	integral<_Tp> &&
	!signed_integral<_Tp>;

template <class _Tp>
concept floating_point =
	is_floating_point_v<_Tp>;

// Concept helpers for the internal type traits for the fundamental types.

template <class _Tp>
concept __libcpp_unsigned_integer =
	__libcpp_is_unsigned_integer<_Tp>::value;

template <class _Tp>
concept __libcpp_signed_integer =
	__libcpp_is_signed_integer<_Tp>::value;

template <class _Tp>
concept __libcpp_integer =
	__libcpp_unsigned_integer<_Tp> ||
	__libcpp_signed_integer<_Tp>;

}

#endif // __KFS_OWN_LIBCXX___CONCEPTS_ARITHMETIC_HPP__
