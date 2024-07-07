/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_nothrow_move_assignable.hpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:55:56 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_NOTHROW_MOVE_ASSIGNABLE_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_NOTHROW_MOVE_ASSIGNABLE_HPP__

# include <__type_traits/add_lvalue_reference.hpp>
# include <__type_traits/add_rvalue_reference.hpp>
# include <__type_traits/integral_constant.hpp>

namespace std {

template <class _Tp>
struct is_nothrow_move_assignable : public integral_constant<bool,
	__is_nothrow_assignable(__add_lvalue_reference_t<_Tp>, __add_rvalue_reference_t<_Tp>)> {};

template <class _Tp>
inline constexpr bool is_nothrow_move_assignable_v = is_nothrow_move_assignable<_Tp>::value;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_NOTHROW_MOVE_ASSIGNABLE_HPP__
