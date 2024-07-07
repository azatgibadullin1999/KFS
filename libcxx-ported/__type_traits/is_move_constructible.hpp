/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_move_constructible.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:25:08 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_MOVE_CONSTRUCTIBLE_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_MOVE_CONSTRUCTIBLE_HPP__

# include <__type_traits/add_rvalue_reference.hpp>
# include <__type_traits/integral_constant.hpp>

namespace std {

template <class _Tp>
struct is_move_constructible : public integral_constant<bool,
	__is_constructible(_Tp, __add_rvalue_reference_t<_Tp>)> {};

template <class _Tp>
inline constexpr bool is_move_constructible_v = is_move_constructible<_Tp>::value;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_MOVE_CONSTRUCTIBLE_HPP__
