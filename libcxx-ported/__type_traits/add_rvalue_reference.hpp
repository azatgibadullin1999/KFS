/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rvalue_reference.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 01:01:25 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_ADD_RVALUE_REFERENCE_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_ADD_RVALUE_REFERENCE_HPP__

#include <__type_traits/is_referenceable.hpp>

namespace std {

# if __has_builtin(__add_rvalue_reference)

template <class _Tp>
using __add_rvalue_reference_t = __add_rvalue_reference(_Tp);

#  else

template <class _Tp, bool = __libcpp_is_referenceable<_Tp>::value>
struct __add_rvalue_reference_impl {
	typedef _Tp type;
};

template <class _Tp >
struct __add_rvalue_reference_impl<_Tp, true> {
	typedef _Tp&& type;
};

template <class _Tp>
using __add_rvalue_reference_t = typename __add_rvalue_reference_impl<_Tp>::type;

# endif // __has_builtin(__add_rvalue_reference)

template <class _Tp>
struct add_rvalue_reference {
	using type = __add_rvalue_reference_t<_Tp>;
};

template <class _Tp>
using add_rvalue_reference_t = __add_rvalue_reference_t<_Tp>;


}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_ADD_RVALUE_REFERENCE_HPP__
