/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignable.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:56:51 by larlena           #+#    #+#             */
/*   Updated: 2024/05/31 19:31:30 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___CONCEPTS_ASSIGNABLE_HPP__
# define __KFS_OWN_LIBCXX___CONCEPTS_ASSIGNABLE_HPP__

#include <__concepts/common_reference_with.hpp>
#include <__concepts/same_as.hpp>
#include <__type_traits/is_reference.hpp>
#include <__type_traits/make_const_lvalue_ref.hpp>
#include <__utility/forward.hpp>

namespace std {

template <class _Lhs, class _Rhs>
concept assignable_from =
	is_lvalue_reference_v<_Lhs> &&
	common_reference_with<__make_const_lvalue_ref<_Lhs>, __make_const_lvalue_ref<_Rhs>> &&
	requires(_Lhs __lhs, _Rhs&& __rhs) {
		{ __lhs = std::forward<_Rhs>(__rhs) } -> same_as<_Lhs>;
	};

}

#endif // __KFS_OWN_LIBCXX___CONCEPTS_ASSIGNABLE_HPP__
