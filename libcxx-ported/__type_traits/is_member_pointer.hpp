/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_member_pointer.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:39:41 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_MEMBER_POINTER_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_MEMBER_POINTER_HPP__

#include <__type_traits/integral_constant.hpp>
#include <__type_traits/is_member_function_pointer.hpp>

namespace std {

# if __has_builtin(__is_member_pointer)

template <class _Tp>
struct is_member_pointer : _BoolConstant<__is_member_pointer(_Tp)> {};

template <class _Tp>
inline constexpr bool is_member_pointer_v = __is_member_pointer(_Tp);

#  else // __has_builtin(__is_member_pointer)

template <class _Tp>
struct is_member_pointer : public _BoolConstant<__libcpp_is_member_pointer<__remove_cv_t<_Tp> >::__is_member> {};

template <class _Tp>
inline constexpr bool is_member_pointer_v = is_member_pointer<_Tp>::value;

# endif // __has_builtin(__is_member_pointer)

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_MEMBER_POINTER_HPP__
