/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equality_comparable.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:00:18 by larlena           #+#    #+#             */
/*   Updated: 2024/05/31 19:31:30 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___CONCEPTS_EQUALITY_COMPARABLE_HPP__
# define __KFS_OWN_LIBCXX___CONCEPTS_EQUALITY_COMPARABLE_HPP__

# include <__concepts/boolean_testable.hpp>
# include <__concepts/common_reference_with.hpp>
# include <__type_traits/common_reference.hpp>
# include <__type_traits/make_const_lvalue_ref.hpp>

namespace std {

// [concept.equalitycomparable]

template <class _Tp, class _Up>
concept __weakly_equality_comparable_with =
	requires(__make_const_lvalue_ref<_Tp> __t, __make_const_lvalue_ref<_Up> __u) {
		{ __t == __u } -> __boolean_testable;
		{ __t != __u } -> __boolean_testable;
		{ __u == __t } -> __boolean_testable;
		{ __u != __t } -> __boolean_testable;
	};

template <class _Tp>
concept equality_comparable = __weakly_equality_comparable_with<_Tp, _Tp>;

// clang-format off
template <class _Tp, class _Up>
concept equality_comparable_with =
	equality_comparable<_Tp> && equality_comparable<_Up> &&
	common_reference_with<__make_const_lvalue_ref<_Tp>, __make_const_lvalue_ref<_Up>> &&
	equality_comparable<
		common_reference_t<
			__make_const_lvalue_ref<_Tp>,
			__make_const_lvalue_ref<_Up>>> &&
	__weakly_equality_comparable_with<_Tp, _Up>;
// clang-format on

}

#endif // __KFS_OWN_LIBCXX___CONCEPTS_EQUALITY_COMPARABLE_HPP__
