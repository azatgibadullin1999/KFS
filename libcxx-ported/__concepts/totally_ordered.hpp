/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totally_ordered.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 00:23:59 by larlena           #+#    #+#             */
/*   Updated: 2024/06/01 00:25:10 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___CONCEPTS_TOTALLY_ORDERED_HPP__
# define __KFS_OWN_LIBCXX___CONCEPTS_TOTALLY_ORDERED_HPP__

# include <__concepts/boolean_testable.hpp>
# include <__concepts/equality_comparable.hpp>
# include <__type_traits/common_reference.hpp>
# include <__type_traits/make_const_lvalue_ref.hpp>

namespace std {

// [concept.totallyordered]

template <class _Tp, class _Up>
concept __partially_ordered_with = requires(__make_const_lvalue_ref<_Tp> __t, __make_const_lvalue_ref<_Up> __u) {
  { __t < __u } -> __boolean_testable;
  { __t > __u } -> __boolean_testable;
  { __t <= __u } -> __boolean_testable;
  { __t >= __u } -> __boolean_testable;
  { __u < __t } -> __boolean_testable;
  { __u > __t } -> __boolean_testable;
  { __u <= __t } -> __boolean_testable;
  { __u >= __t } -> __boolean_testable;
};

template <class _Tp>
concept totally_ordered = equality_comparable<_Tp> && __partially_ordered_with<_Tp, _Tp>;

// clang-format off
template <class _Tp, class _Up>
concept totally_ordered_with =
    totally_ordered<_Tp> && totally_ordered<_Up> &&
    equality_comparable_with<_Tp, _Up> &&
    totally_ordered<
        common_reference_t<
            __make_const_lvalue_ref<_Tp>,
            __make_const_lvalue_ref<_Up>>> &&
    __partially_ordered_with<_Tp, _Up>;
// clang-format on

}

#endif // __KFS_OWN_LIBCXX___CONCEPTS_TOTALLY_ORDERED_HPP__
