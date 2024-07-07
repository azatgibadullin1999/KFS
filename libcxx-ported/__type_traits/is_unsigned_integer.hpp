/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_unsigned_integer.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:04:09 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_UNSIGNED_INTEGER_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_UNSIGNED_INTEGER_HPP__

#include <__type_traits/integral_constant.hpp>

namespace std {

// clang-format off
template <class _Tp> struct __libcpp_is_unsigned_integer                     : public false_type {};
template <>          struct __libcpp_is_unsigned_integer<unsigned char>      : public true_type {};
template <>          struct __libcpp_is_unsigned_integer<unsigned short>     : public true_type {};
template <>          struct __libcpp_is_unsigned_integer<unsigned int>       : public true_type {};
template <>          struct __libcpp_is_unsigned_integer<unsigned long>      : public true_type {};
template <>          struct __libcpp_is_unsigned_integer<unsigned long long> : public true_type {};
// template <>          struct __libcpp_is_unsigned_integer<__uint128_t>        : public true_type {};
// clang-format on

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_UNSIGNED_INTEGER_HPP__
