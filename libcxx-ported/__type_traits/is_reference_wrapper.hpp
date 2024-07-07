/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_reference_wrapper.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 00:04:47 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_REFERENCE_WRAPPER_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_REFERENCE_WRAPPER_HPP__

# include <__type_traits/integral_constant.hpp>
# include <__type_traits/remove_cv.hpp>

namespace std {

template <class _Tp>
class reference_wrapper;

template <class _Tp>
struct __is_reference_wrapper_impl : public false_type {};
template <class _Tp>
struct __is_reference_wrapper_impl<reference_wrapper<_Tp> > : public true_type {};
template <class _Tp>
struct __is_reference_wrapper : public __is_reference_wrapper_impl<__remove_cv_t<_Tp> > {};

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_REFERENCE_WRAPPER_HPP__
