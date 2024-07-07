/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pointer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 00:08:04 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_POINTER_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_POINTER_HPP__

# include <__type_traits/integral_constant.hpp>
# include <__type_traits/remove_cv.hpp>

namespace std {

# if __has_builtin(__is_pointer)

template <class _Tp>
struct is_pointer : _BoolConstant<__is_pointer(_Tp)> {};

template <class _Tp>
inline constexpr bool is_pointer_v = __is_pointer(_Tp);

#  else // __has_builtin(__is_pointer)

template <class _Tp>
struct __libcpp_is_pointer : public false_type {};
template <class _Tp>
struct __libcpp_is_pointer<_Tp*> : public true_type {};

template <class _Tp>
struct __libcpp_remove_objc_qualifiers {
	typedef _Tp type;
};
// #  if defined(_LIBCPP_HAS_OBJC_ARC)
// // clang-format off
// template <class _Tp> struct __libcpp_remove_objc_qualifiers<_Tp __strong> { typedef _Tp type; };
// template <class _Tp> struct __libcpp_remove_objc_qualifiers<_Tp __weak> { typedef _Tp type; };
// template <class _Tp> struct __libcpp_remove_objc_qualifiers<_Tp __autoreleasing> { typedef _Tp type; };
// template <class _Tp> struct __libcpp_remove_objc_qualifiers<_Tp __unsafe_unretained> { typedef _Tp type; };
// // clang-format on
// #  endif

template <class _Tp>
struct is_pointer : public __libcpp_is_pointer<typename __libcpp_remove_objc_qualifiers<__remove_cv_t<_Tp> >::type> {};

template <class _Tp>
inline constexpr bool is_pointer_v = is_pointer<_Tp>::value;

#endif // __has_builtin(__is_pointer)

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_POINTER_HPP__
