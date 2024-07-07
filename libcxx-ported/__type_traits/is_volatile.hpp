/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_volatile.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:57:46 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_VOLATILE_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_VOLATILE_HPP__

# include <__type_traits/integral_constant.hpp>

namespace std {

# if __has_builtin(__is_volatile)

template <class _Tp>
struct is_volatile : _BoolConstant<__is_volatile(_Tp)> {};

template <class _Tp>
inline constexpr bool is_volatile_v = __is_volatile(_Tp);

#  else

template <class _Tp>
struct is_volatile : public false_type {};
template <class _Tp>
struct is_volatile<_Tp volatile> : public true_type {};

template <class _Tp>
inline constexpr bool is_volatile_v = is_volatile<_Tp>::value;

# endif

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_VOLATILE_HPP__
