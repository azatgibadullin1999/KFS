/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_nothrow_destructible.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:20:28 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_NOTHROW_DESTRUCTIBLE_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_NOTHROW_DESTRUCTIBLE_HPP__

# include <__type_traits/integral_constant.hpp>
# include <__type_traits/is_destructible.hpp>
# include <__type_traits/is_reference.hpp>
# include <__type_traits/is_scalar.hpp>
# include <__type_traits/remove_all_extents.hpp>
# include <__utility/declval.hpp>
# include <cstddef>

namespace std {

template <class _Tp>
struct __libcpp_nothrow_destructor : public integral_constant<bool, is_scalar<_Tp>::value || is_reference<_Tp>::value> {
};

template <class _Tp>
struct is_nothrow_destructible : public __libcpp_nothrow_destructor<__remove_all_extents_t<_Tp> > {
};

template <class _Tp>
struct is_nothrow_destructible<_Tp[]> : public false_type {};

template <class _Tp>
inline constexpr bool is_nothrow_destructible_v = is_nothrow_destructible<_Tp>::value;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_NOTHROW_DESTRUCTIBLE_HPP__
