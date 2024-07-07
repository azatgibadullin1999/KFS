/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_reference.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:30:31 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:35:31 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_REFERENCE_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_REFERENCE_HPP__

#include <__type_traits/integral_constant.hpp>

namespace std {

#if __has_builtin(__is_lvalue_reference) && __has_builtin(__is_rvalue_reference) && __has_builtin(__is_reference)

template <class _Tp>
struct is_lvalue_reference : _BoolConstant<__is_lvalue_reference(_Tp)> {};

template <class _Tp>
struct is_rvalue_reference : _BoolConstant<__is_rvalue_reference(_Tp)> {};

template <class _Tp>
struct is_reference : _BoolConstant<__is_reference(_Tp)> {};

template <class _Tp>
inline constexpr bool is_reference_v = __is_reference(_Tp);
template <class _Tp>
inline constexpr bool is_lvalue_reference_v = __is_lvalue_reference(_Tp);
template <class _Tp>
inline constexpr bool is_rvalue_reference_v = __is_rvalue_reference(_Tp);

#else // __has_builtin(__is_lvalue_reference) && etc...

template <class _Tp>
struct is_lvalue_reference : public false_type {};
template <class _Tp>
struct is_lvalue_reference<_Tp&> : public true_type {};

template <class _Tp>
struct is_rvalue_reference : public false_type {};
template <class _Tp>
struct is_rvalue_reference<_Tp&&> : public true_type {};

template <class _Tp>
struct is_reference : public false_type {};
template <class _Tp>
struct is_reference<_Tp&> : public true_type {};
template <class _Tp>
struct is_reference<_Tp&&> : public true_type {};

template <class _Tp>
inline constexpr bool is_reference_v = is_reference<_Tp>::value;

template <class _Tp>
inline constexpr bool is_lvalue_reference_v = is_lvalue_reference<_Tp>::value;

template <class _Tp>
inline constexpr bool is_rvalue_reference_v = is_rvalue_reference<_Tp>::value;

#endif // __has_builtin(__is_lvalue_reference) && etc...

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_REFERENCE_HPP__
