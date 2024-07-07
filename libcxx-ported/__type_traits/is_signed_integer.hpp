/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_signed_integer.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:02:04 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_SIGNED_INTEGER_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_SIGNED_INTEGER_HPP__

#include <__type_traits/integral_constant.hpp>

namespace std {

// clang-format off
template <class _Tp> struct __libcpp_is_signed_integer                   : public false_type {};
template <>          struct __libcpp_is_signed_integer<signed char>      : public true_type {};
template <>          struct __libcpp_is_signed_integer<signed short>     : public true_type {};
template <>          struct __libcpp_is_signed_integer<signed int>       : public true_type {};
template <>          struct __libcpp_is_signed_integer<signed long>      : public true_type {};
template <>          struct __libcpp_is_signed_integer<signed long long> : public true_type {};
// template <>          struct __libcpp_is_signed_integer<__int128_t>       : public true_type {};
// clang-format on

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_SIGNED_INTEGER_HPP__
