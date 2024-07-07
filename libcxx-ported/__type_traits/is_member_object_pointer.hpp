/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_member_object_pointer.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 00:02:54 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_MEMBER_OBJECT_POINTER_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_MEMBER_OBJECT_POINTER_HPP__

# include <__type_traits/integral_constant.hpp>

namespace std {

# if __has_builtin(__is_member_object_pointer)

template <class _Tp>
struct is_member_object_pointer : _BoolConstant<__is_member_object_pointer(_Tp)> {};

template <class _Tp>
inline constexpr bool is_member_object_pointer_v = __is_member_object_pointer(_Tp);

#  else // __has_builtin(__is_member_object_pointer)

template <class _Tp>
struct is_member_object_pointer : public _BoolConstant<__libcpp_is_member_pointer<__remove_cv_t<_Tp> >::__is_obj> {};

template <class _Tp>
inline constexpr bool is_member_object_pointer_v = is_member_object_pointer<_Tp>::value;

# endif // __has_builtin(__is_member_object_pointer)

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_MEMBER_OBJECT_POINTER_HPP__
