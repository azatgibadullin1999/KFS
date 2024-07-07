/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_function.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:25:02 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_FUNCTION_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_FUNCTION_HPP__

# include <__type_traits/integral_constant.hpp>
# include <__type_traits/is_const.hpp>
# include <__type_traits/is_reference.hpp>

namespace std {

#if __has_builtin(__is_function)

template <class _Tp>
struct is_function : integral_constant<bool, __is_function(_Tp)> {};

#else

template <class _Tp>
struct is_function : public integral_constant<bool, !(is_reference<_Tp>::value || is_const<const _Tp>::value)> {};

#endif // __has_builtin(__is_function)

template <class _Tp>
inline constexpr bool is_function_v = is_function<_Tp>::value;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_FUNCTION_HPP__
