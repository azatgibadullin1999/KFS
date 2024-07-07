/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_nothrow_move_constructible.hpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:57:56 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:24:14 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_NOTHROW_MOVE_CONSTRUCTIBLE_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_NOTHROW_MOVE_CONSTRUCTIBLE_HPP__

namespace std {

// TODO: remove this implementation once https://gcc.gnu.org/bugzilla/show_bug.cgi?id=106611 is fixed
# ifndef _LIBCPP_COMPILER_GCC

template <class _Tp>
struct is_nothrow_move_constructible : public integral_constant<bool,
	__is_nothrow_constructible(_Tp, __add_rvalue_reference_t<_Tp>)> {};

#  else // _LIBCPP_COMPILER_GCC

template <class _Tp>
struct is_nothrow_move_constructible : public is_nothrow_constructible<_Tp, __add_rvalue_reference_t<_Tp> > {};

# endif // _LIBCPP_COMPILER_GCC

template <class _Tp>
inline constexpr bool is_nothrow_move_constructible_v = is_nothrow_move_constructible<_Tp>::value;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_NOTHROW_MOVE_CONSTRUCTIBLE_HPP__
