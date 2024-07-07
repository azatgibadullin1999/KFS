/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_floating_point.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:34:41 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_FLOATING_POINT_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_FLOATING_POINT_HPP__

#include <__type_traits/integral_constant.hpp>
#include <__type_traits/remove_cv.hpp>

namespace std {

// clang-format off
template <class _Tp> struct __libcpp_is_floating_point              : public false_type {};
template <>          struct __libcpp_is_floating_point<float>       : public true_type {};
template <>          struct __libcpp_is_floating_point<double>      : public true_type {};
template <>          struct __libcpp_is_floating_point<long double> : public true_type {};
// clang-format on

template <class _Tp>
struct is_floating_point : public __libcpp_is_floating_point<__remove_cv_t<_Tp> > {};

template <class _Tp>
inline constexpr bool is_floating_point_v = is_floating_point<_Tp>::value;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_FLOATING_POINT_HPP__
