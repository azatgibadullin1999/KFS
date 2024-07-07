/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_void.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:33:07 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_VOID_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_VOID_HPP__

#include <__type_traits/integral_constant.hpp>
#include <__type_traits/is_same.hpp>
#include <__type_traits/remove_cv.hpp>

namespace std {

#if __has_builtin(__is_void)

template <class _Tp>
struct is_void : _BoolConstant<__is_void(_Tp)> {};

template <class _Tp>
inline constexpr bool is_void_v = __is_void(_Tp);

#else

template <class _Tp>
struct is_void : public is_same<__remove_cv_t<_Tp>, void> {};

template <class _Tp>
inline constexpr bool is_void_v = is_void<_Tp>::value;

#endif // __has_builtin(__is_void)

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_VOID_HPP__
