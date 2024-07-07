/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_object.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:38:38 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_OBJECT_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_OBJECT_HPP__

# include <__type_traits/integral_constant.hpp>
# include <__type_traits/is_array.hpp>
# include <__type_traits/is_class.hpp>
# include <__type_traits/is_scalar.hpp>
# include <__type_traits/is_union.hpp>

namespace std {


# if __has_builtin(__is_object)

template <class _Tp>
struct is_object : _BoolConstant<__is_object(_Tp)> {};

template <class _Tp>
inline constexpr bool is_object_v = __is_object(_Tp);

#  else // __has_builtin(__is_object)

template <class _Tp>
struct is_object : public integral_constant<bool,
	is_scalar<_Tp>::value ||
	is_array<_Tp>::value ||
	is_union<_Tp>::value ||
	is_class<_Tp>::value > {};

template <class _Tp>
inline constexpr bool is_object_v = is_object<_Tp>::value;

# endif // __has_builtin(__is_object)


}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_OBJECT_HPP__
