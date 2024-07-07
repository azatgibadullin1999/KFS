/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:34:41 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_SAME_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_SAME_HPP__

#include <__type_traits/integral_constant.hpp>

namespace std {

template <class _Tp, class _Up>
struct is_same : _BoolConstant<__is_same(_Tp, _Up)> {};

template <class _Tp, class _Up>
inline constexpr bool is_same_v = __is_same(_Tp, _Up);

// _IsSame<T,U> has the same effect as is_same<T,U> but instantiates fewer types:
// is_same<A,B> and is_same<C,D> are guaranteed to be different types, but
// _IsSame<A,B> and _IsSame<C,D> are the same type (namely, false_type).
// Neither GCC nor Clang can mangle the __is_same builtin, so _IsSame
// mustn't be directly used anywhere that contributes to name-mangling
// (such as in a dependent return type).

template <class _Tp, class _Up>
using _IsSame = _BoolConstant<__is_same(_Tp, _Up)>;

template <class _Tp, class _Up>
using _IsNotSame = _BoolConstant<!__is_same(_Tp, _Up)>;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_SAME_HPP__
