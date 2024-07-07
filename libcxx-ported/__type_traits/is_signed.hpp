/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_signed.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:59:52 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_SIGNED_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_SIGNED_HPP__

#include <__type_traits/integral_constant.hpp>
#include <__type_traits/is_arithmetic.hpp>
#include <__type_traits/is_integral.hpp>

namespace std {

#if __has_builtin(__is_signed)

template <class _Tp>
struct is_signed : _BoolConstant<__is_signed(_Tp)> {};

template <class _Tp>
inline constexpr bool is_signed_v = __is_signed(_Tp);

#else // __has_builtin(__is_signed)

template <class _Tp, bool = is_integral<_Tp>::value>
struct __libcpp_is_signed_impl : public _BoolConstant<(_Tp(-1) < _Tp(0))> {};

template <class _Tp>
struct __libcpp_is_signed_impl<_Tp, false> : public true_type {}; // floating point

template <class _Tp, bool = is_arithmetic<_Tp>::value>
struct __libcpp_is_signed : public __libcpp_is_signed_impl<_Tp> {};

template <class _Tp>
struct __libcpp_is_signed<_Tp, false> : public false_type {};

template <class _Tp>
struct is_signed : public __libcpp_is_signed<_Tp> {};

template <class _Tp>
inline constexpr bool is_signed_v = is_signed<_Tp>::value;

#endif // __has_builtin(__is_signed)

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_SIGNED_HPP__
