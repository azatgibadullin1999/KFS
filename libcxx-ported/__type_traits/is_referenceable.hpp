/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_referenceable.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 01:07:13 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:37:30 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_REFERENCEABLE_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_REFERENCEABLE_HPP__

# include <__type_traits/integral_constant.hpp>
# include <__type_traits/is_same.hpp>

namespace std {

# if __has_builtin(__is_referenceable)

template <class _Tp>
struct __libcpp_is_referenceable : integral_constant<bool, __is_referenceable(_Tp)> {};

#  else

struct __libcpp_is_referenceable_impl {
	template <class _Tp>
	static _Tp& __test(int);
	template <class _Tp>
	static false_type __test(...);
};

template <class _Tp>
struct __libcpp_is_referenceable : integral_constant<bool, _IsNotSame<decltype(__libcpp_is_referenceable_impl::__test<_Tp>(0)), false_type>::value> { };

# endif // __has_builtin(__is_referenceable)

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_REFERENCEABLE_HPP__
