/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_enum.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:40:13 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_ENUM_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_ENUM_HPP__

#include <__type_traits/integral_constant.hpp>

namespace std {

template <class _Tp>
struct is_enum : public integral_constant<bool, __is_enum(_Tp)> {};

template <class _Tp>
inline constexpr bool is_enum_v = __is_enum(_Tp);

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_ENUM_HPP__
