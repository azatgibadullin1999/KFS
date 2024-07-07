/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_scalar.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:28:58 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_SCALAR_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_SCALAR_HPP__

# include <__type_traits/integral_constant.hpp>
# include <__type_traits/is_arithmetic.hpp>
# include <__type_traits/is_enum.hpp>
# include <__type_traits/is_member_pointer.hpp>
# include <__type_traits/is_null_pointer.hpp>
# include <__type_traits/is_pointer.hpp>

namespace std {


# if __has_builtin(__is_scalar)

template <class _Tp>
struct is_scalar : _BoolConstant<__is_scalar(_Tp)> {};

template <class _Tp>
inline constexpr bool is_scalar_v = __is_scalar(_Tp);

#  else // __has_builtin(__is_scalar)

template <class _Tp>
struct __is_block : false_type {};
// #  if defined(_LIBCPP_HAS_EXTENSION_BLOCKS)
// template <class _Rp, class... _Args>
// struct __is_block<_Rp (^)(_Args...)> : true_type {};
// #  endif

// clang-format off
template <class _Tp>
struct is_scalar : public integral_constant< bool,
	is_arithmetic<_Tp>::value ||
	is_member_pointer<_Tp>::value ||
	is_pointer<_Tp>::value ||
	__is_nullptr_t<_Tp>::value ||
	__is_block<_Tp>::value ||
	is_enum<_Tp>::value> {};
// clang-format on

template <>
struct is_scalar<nullptr_t> : public true_type {};

template <class _Tp>
inline constexpr bool is_scalar_v = is_scalar<_Tp>::value;

# endif // __has_builtin(__is_scalar)

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_SCALAR_HPP__
