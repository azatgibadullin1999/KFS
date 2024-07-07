/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   derived_from.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:56:50 by larlena           #+#    #+#             */
/*   Updated: 2024/06/01 00:13:56 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___CONCEPTS_DERIVED_FROM_HPP__
# define __KFS_OWN_LIBCXX___CONCEPTS_DERIVED_FROM_HPP__

# include <__type_traits/is_base_of.hpp>
# include <__type_traits/is_convertible.hpp>

namespace std {

// [concept.derived]

template <class _Dp, class _Bp>
concept derived_from = is_base_of_v<_Bp, _Dp> && is_convertible_v<const volatile _Dp*, const volatile _Bp*>;

}

#endif // __KFS_OWN_LIBCXX___CONCEPTS_DERIVED_FROM_HPP__
