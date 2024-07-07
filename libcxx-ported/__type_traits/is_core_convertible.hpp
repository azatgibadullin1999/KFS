/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_core_convertible.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 00:00:52 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_CORE_CONVERTIBLE_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_CORE_CONVERTIBLE_HPP__

# include <__type_traits/integral_constant.hpp>

namespace std {

// [conv.general]/3 says "E is convertible to T" whenever "T t=E;" is well-formed.
// We can't test for that, but we can test implicit convertibility by passing it
// to a function. Notice that __is_core_convertible<void,void> is false,
// and __is_core_convertible<immovable-type,immovable-type> is true in C++17 and later.

template <class _Tp, class _Up, class = void>
struct __is_core_convertible : public false_type {};

template <class _Tp, class _Up>
struct __is_core_convertible<_Tp, _Up, decltype(static_cast<void (*)(_Up)>(0)(static_cast<_Tp (*)()>(0)()))>
	: public true_type {};

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_CORE_CONVERTIBLE_HPP__
