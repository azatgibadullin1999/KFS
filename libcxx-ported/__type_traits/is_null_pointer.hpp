/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_null_pointer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:45:47 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_NULL_POINTER_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_NULL_POINTER_HPP__

# include <__type_traits/integral_constant.hpp>
# include <__type_traits/remove_cv.hpp>
# include <cstddef>

namespace std {

template <class _Tp>
struct __is_nullptr_t_impl : public false_type {};
template <>
struct __is_nullptr_t_impl<nullptr_t> : public true_type {};

template <class _Tp>
struct __is_nullptr_t : public __is_nullptr_t_impl<__remove_cv_t<_Tp> > {};

template <class _Tp>
struct is_null_pointer : public __is_nullptr_t_impl<__remove_cv_t<_Tp> > {};

template <class _Tp>
inline constexpr bool is_null_pointer_v = is_null_pointer<_Tp>::value;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_NULL_POINTER_HPP__
