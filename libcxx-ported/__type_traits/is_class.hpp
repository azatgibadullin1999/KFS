/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_class.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:37:44 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_CLASS_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_CLASS_HPP__

# include <__type_traits/integral_constant.hpp>

namespace std {

template <class _Tp>
struct is_class : public integral_constant<bool, __is_class(_Tp)> {};

template <class _Tp>
inline constexpr bool is_class_v = __is_class(_Tp);

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_CLASS_HPP__
