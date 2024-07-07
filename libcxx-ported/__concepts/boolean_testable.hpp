/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boolean_testable.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:03:13 by larlena           #+#    #+#             */
/*   Updated: 2024/05/31 19:31:30 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___CONCEPTS_BOOLEAN_TESTABLE_HPP__
# define __KFS_OWN_LIBCXX___CONCEPTS_BOOLEAN_TESTABLE_HPP__

# include <__concepts/convertible_to.hpp>
# include <__utility/forward.hpp>

namespace std {

// [concepts.booleantestable]

template <class _Tp>
concept __boolean_testable_impl = convertible_to<_Tp, bool>;

template <class _Tp>
concept __boolean_testable = __boolean_testable_impl<_Tp> && requires(_Tp&& __t) {
	{ !std::forward<_Tp>(__t) } -> __boolean_testable_impl;
};

}

#endif // __KFS_OWN_LIBCXX___CONCEPTS_BOOLEAN_TESTABLE_HPP__
