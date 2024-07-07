/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_nothrow_assignable.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:09:39 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_NOTHROW_ASSIGNABLE_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_NOTHROW_ASSIGNABLE_HPP__

# include <__type_traits/integral_constant.hpp>

namespace std {

template <class _Tp, class _Arg>
struct is_nothrow_assignable : public integral_constant<bool,
	__is_nothrow_assignable(_Tp, _Arg)> {};

template <class _Tp, class _Arg>
inline constexpr bool is_nothrow_assignable_v = __is_nothrow_assignable(_Tp, _Arg);

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_NOTHROW_ASSIGNABLE_HPP__
