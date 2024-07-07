/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_constructible.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:49:01 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_CONSTRUCTIBLE_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_CONSTRUCTIBLE_HPP__

#include <__type_traits/integral_constant.hpp>

namespace std {

template <class _Tp, class... _Args>
struct is_constructible : public integral_constant<bool, __is_constructible(_Tp, _Args...)> {};

template <class _Tp, class... _Args>
inline constexpr bool is_constructible_v = __is_constructible(_Tp, _Args...);

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_CONSTRUCTIBLE_HPP__
