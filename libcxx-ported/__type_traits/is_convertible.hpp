/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_convertible.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:03:33 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_CONVERTIBLE_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_CONVERTIBLE_HPP__

# include <__type_traits/integral_constant.hpp>
# include <__type_traits/is_array.hpp>
# include <__type_traits/is_function.hpp>
#include <__type_traits/is_void.hpp>
#include <__type_traits/remove_reference.hpp>
#include <__utility/declval.hpp>
#include <cstddef>


namespace std {

template <class _T1, class _T2>
struct is_convertible : public integral_constant<bool, __is_convertible(_T1, _T2)> {};

template <class _From, class _To>
inline constexpr bool is_convertible_v = __is_convertible(_From, _To);

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_CONVERTIBLE_HPP__
