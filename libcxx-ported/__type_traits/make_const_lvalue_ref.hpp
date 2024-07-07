/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_const_lvalue_ref.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:23:42 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_MAKE_CONST_LVALUE_REF_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_MAKE_CONST_LVALUE_REF_HPP__

#include <__type_traits/remove_reference.hpp>

namespace std {

template <class _Tp>
using __make_const_lvalue_ref = const __libcpp_remove_reference_t<_Tp>&;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_MAKE_CONST_LVALUE_REF_HPP__
