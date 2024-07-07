/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_array.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:21:04 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_ARRAY_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_ARRAY_HPP__

# include <__type_traits/integral_constant.hpp>
// #include <cstddef>

namespace std {

template <class _Tp>
struct is_array : public false_type {};
template <class _Tp>
struct is_array<_Tp[]> : public true_type {};
template <class _Tp, size_t _Np>
struct is_array<_Tp[_Np]> : public true_type {};

template <class _Tp>
inline constexpr bool is_array_v = is_array<_Tp>::value;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_ARRAY_HPP__
