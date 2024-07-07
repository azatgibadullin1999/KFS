/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_primary_template.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:37:06 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_PRIMARY_TEMPLATE_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_PRIMARY_TEMPLATE_HPP__

# include <__type_traits/enable_if.hpp>
# include <__type_traits/is_same.hpp>
# include <__type_traits/is_valid_expansion.hpp>

namespace std {

template <class _Tp>
using __test_for_primary_template = __enable_if_t<_IsSame<_Tp, typename _Tp::__primary_template>::value>;

template <class _Tp>
using __is_primary_template = _IsValidExpansion<__test_for_primary_template, _Tp>;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_PRIMARY_TEMPLATE_HPP__
