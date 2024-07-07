/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_member_function_pointer.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:41:47 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_MEMBER_FUNCTION_POINTER_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_MEMBER_FUNCTION_POINTER_HPP__

# include <__type_traits/integral_constant.hpp>
# include <__type_traits/is_function.hpp>
# include <__type_traits/remove_cv.hpp>
# include <cstddef>

namespace std {

template <class _Tp>
struct __libcpp_is_member_pointer {
	enum {
		__is_member = false,
		__is_func   = false,
		__is_obj    = false };
};
template <class _Tp, class _Up>
struct __libcpp_is_member_pointer<_Tp _Up::*> {
	enum {
		__is_member = true,
		__is_func   = is_function<_Tp>::value,
		__is_obj    = !__is_func,
	};
};

# if __has_builtin(__is_member_function_pointer)

template <class _Tp>
struct is_member_function_pointer : _BoolConstant<__is_member_function_pointer(_Tp)> {};

template <class _Tp>
inline constexpr bool is_member_function_pointer_v = __is_member_function_pointer(_Tp);

#  else // __has_builtin(__is_member_function_pointer)

template <class _Tp>
struct is_member_function_pointer
	: public _BoolConstant<__libcpp_is_member_pointer<__remove_cv_t<_Tp> >::__is_func> {};

template <class _Tp>
inline constexpr bool is_member_function_pointer_v = is_member_function_pointer<_Tp>::value;

# endif // __has_builtin(__is_member_function_pointer)

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_MEMBER_FUNCTION_POINTER_HPP__
