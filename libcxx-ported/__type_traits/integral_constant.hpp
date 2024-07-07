/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral_constant.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:13:51 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_INTEGRAL_CONSTANT_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_INTEGRAL_CONSTANT_HPP__

namespace std {

template <class _Tp, _Tp __v>
struct integral_constant {
	static constexpr const _Tp value = __v;
	typedef _Tp value_type;
	typedef integral_constant type;
	constexpr operator value_type() const noexcept { return value; }

	constexpr value_type operator()() const noexcept { return value; }
};

template <class _Tp, _Tp __v>
constexpr const _Tp integral_constant<_Tp, __v>::value;

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;


template <bool _Val>
using _BoolConstant = integral_constant<bool, _Val>;

template <bool __b>
using bool_constant = integral_constant<bool, __b>;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_INTEGRAL_CONSTANT_HPP__
