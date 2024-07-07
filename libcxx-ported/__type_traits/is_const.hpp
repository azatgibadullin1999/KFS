/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_const.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:28:09 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_CONST_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_CONST_HPP__

# include <__type_traits/integral_constant.hpp>

namespace std {

#if __has_builtin(__is_const)

template <class _Tp>
struct is_const : _BoolConstant<__is_const(_Tp)> {};

template <class _Tp>
inline constexpr bool is_const_v = __is_const(_Tp);

#else

template <class _Tp>
struct is_const : public false_type {};
template <class _Tp>
struct is_const<_Tp const> : public true_type {};

template <class _Tp>
inline constexpr bool is_const_v = is_const<_Tp>::value;

#endif // __has_builtin(__is_const)


}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_CONST_HPP__
