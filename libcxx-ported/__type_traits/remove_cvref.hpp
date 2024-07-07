/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_cvref.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:02:59 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_REMOVE_CVREF_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_REMOVE_CVREF_HPP__

#include <__type_traits/is_same.hpp>
#include <__type_traits/remove_cv.hpp>
#include <__type_traits/remove_reference.hpp>

namespace std {

# if __has_builtin(__remove_cvref) && !defined(_LIBCPP_COMPILER_GCC)

template <class _Tp>
using __remove_cvref_t = __remove_cvref(_Tp);

#  else

template <class _Tp>
using __remove_cvref_t = __remove_cv_t<__libcpp_remove_reference_t<_Tp> >;

# endif // __has_builtin(__remove_cvref)

template <class _Tp, class _Up>
struct __is_same_uncvref : _IsSame<__remove_cvref_t<_Tp>, __remove_cvref_t<_Up> > {};

template <class _Tp>
struct remove_cvref {
	using type = __remove_cvref_t<_Tp>;
};

template <class _Tp>
using remove_cvref_t = __remove_cvref_t<_Tp>;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_REMOVE_CVREF_HPP__
