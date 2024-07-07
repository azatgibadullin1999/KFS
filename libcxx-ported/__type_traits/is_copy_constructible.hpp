/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_copy_constructible.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:15:36 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:24:44 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_COPY_CONSTRUCTIBLE_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_COPY_CONSTRUCTIBLE_HPP__

#include <__type_traits/add_const.hpp>
#include <__type_traits/add_lvalue_reference.hpp>
#include <__type_traits/integral_constant.hpp>

namespace std {

template <class _Tp>
struct is_copy_constructible : public integral_constant<bool,
	__is_constructible(_Tp, __add_lvalue_reference_t<typename add_const<_Tp>::type>)> {};

template <class _Tp>
inline constexpr bool is_copy_constructible_v = is_copy_constructible<_Tp>::value;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_COPY_CONSTRUCTIBLE_HPP__
