/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_base_of.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:58:14 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_CLASS_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_CLASS_HPP__

# include <__type_traits/integral_constant.hpp>

namespace std {

template <class _Bp, class _Dp>
struct is_base_of : public integral_constant<bool, __is_base_of(_Bp, _Dp)> {};

template <class _Bp, class _Dp>
inline constexpr bool is_base_of_v = __is_base_of(_Bp, _Dp);

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_CLASS_HPP__
