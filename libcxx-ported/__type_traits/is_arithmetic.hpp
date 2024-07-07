/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_arithmetic.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:33:09 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_ARITHMETIC_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_ARITHMETIC_HPP__

# include <__type_traits/integral_constant.hpp>
# include <__type_traits/is_floating_point.hpp>
# include <__type_traits/is_integral.hpp>

namespace std {

template <class _Tp>
struct is_arithmetic : public integral_constant<bool,
	is_integral<_Tp>::value ||
	is_floating_point<_Tp>::value> {};

template <class _Tp>
inline constexpr bool is_arithmetic_v = is_arithmetic<_Tp>::value;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_ARITHMETIC_HPP__
