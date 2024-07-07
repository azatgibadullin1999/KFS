/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pointer.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:54:21 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_ADD_POINTER_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_ADD_POINTER_HPP__

#include <__type_traits/is_referenceable.hpp>
#include <__type_traits/is_same.hpp>
#include <__type_traits/is_void.hpp>
#include <__type_traits/remove_cv.hpp>
#include <__type_traits/remove_reference.hpp>

namespace std {

# if __has_builtin(__add_pointer)

template <class _Tp>
using __add_pointer_t = __add_pointer(_Tp);

#  else

template <class _Tp, bool = __libcpp_is_referenceable<_Tp>::value || is_void<_Tp>::value>
struct __add_pointer_impl {
	typedef __libcpp_remove_reference_t<_Tp>* type;
};
template <class _Tp>
struct __add_pointer_impl<_Tp, false> {
	typedef _Tp type;
};

template <class _Tp>
using __add_pointer_t = typename __add_pointer_impl<_Tp>::type;

# endif // !defined(_LIBCPP_WORKAROUND_OBJCXX_COMPILER_INTRINSICS) && __has_builtin(__add_pointer)

template <class _Tp>
struct add_pointer {
	using type = __add_pointer_t<_Tp>;
};

template <class _Tp>
using add_pointer_t = __add_pointer_t<_Tp>;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_ADD_POINTER_HPP__
