/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_swappable.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:28:19 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:38:45 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_SWAPPABLE_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_SWAPPABLE_HPP__

#include <__type_traits/add_lvalue_reference.hpp>
#include <__type_traits/conditional.hpp>
#include <__type_traits/enable_if.hpp>
#include <__type_traits/is_move_assignable.hpp>
#include <__type_traits/is_move_constructible.hpp>
#include <__type_traits/is_nothrow_move_assignable.hpp>
#include <__type_traits/is_nothrow_move_constructible.hpp>
#include <__type_traits/is_referenceable.hpp>
#include <__type_traits/is_same.hpp>
#include <__type_traits/is_void.hpp>
#include <__type_traits/nat.hpp>
#include <__utility/declval.hpp>
#include <cstddef>

namespace std {

template <class _Tp>
struct __is_swappable;
template <class _Tp>
struct __is_nothrow_swappable;

template <class _Tp>
inline constexpr void swap(_Tp& __x, _Tp& __y)
    noexcept(is_nothrow_move_constructible<_Tp>::value&& is_nothrow_move_assignable<_Tp>::value);

template <class _Tp, size_t _Np, __enable_if_t<__is_swappable<_Tp>::value, int> = 0>
inline constexpr void swap(_Tp (&__a)[_Np], _Tp (&__b)[_Np])
    noexcept(__is_nothrow_swappable<_Tp>::value);

namespace __detail {
// ALL generic swap overloads MUST already have a declaration available at this point.

template <class _Tp, class _Up = _Tp, bool _NotVoid = !is_void<_Tp>::value && !is_void<_Up>::value>
struct __swappable_with {
	template <class _LHS, class _RHS>
	static decltype(swap(std::declval<_LHS>(), std::declval<_RHS>())) __test_swap(int);
	template <class, class>
	static __nat __test_swap(long);

	// Extra parens are needed for the C++03 definition of decltype.
	typedef decltype((__test_swap<_Tp, _Up>(0))) __swap1;
	typedef decltype((__test_swap<_Up, _Tp>(0))) __swap2;

	static const bool value = _IsNotSame<__swap1, __nat>::value && _IsNotSame<__swap2, __nat>::value;
};

template <class _Tp, class _Up>
struct __swappable_with<_Tp, _Up, false> : false_type {};

template <class _Tp, class _Up = _Tp, bool _Swappable = __swappable_with<_Tp, _Up>::value>
struct __nothrow_swappable_with {
	static const bool value = noexcept(swap(std::declval<_Tp>(), std::declval<_Up>()))&& noexcept(
	swap(std::declval<_Up>(), std::declval<_Tp>()));
};

template <class _Tp, class _Up>
struct __nothrow_swappable_with<_Tp, _Up, false> : false_type {};

} // namespace __detail

template <class _Tp>
struct __is_swappable : public integral_constant<bool, __detail::__swappable_with<_Tp&>::value> {};

template <class _Tp>
struct __is_nothrow_swappable : public integral_constant<bool, __detail::__nothrow_swappable_with<_Tp&>::value> {};

template <class _Tp, class _Up>
struct is_swappable_with : public integral_constant<bool, __detail::__swappable_with<_Tp, _Up>::value> {};

template <class _Tp>
struct is_swappable : public __conditional_t<__libcpp_is_referenceable<_Tp>::value,
	is_swappable_with<__add_lvalue_reference_t<_Tp>, __add_lvalue_reference_t<_Tp> >,
	false_type> {};

template <class _Tp, class _Up>
struct is_nothrow_swappable_with : public integral_constant<bool, __detail::__nothrow_swappable_with<_Tp, _Up>::value> {};

template <class _Tp>
struct is_nothrow_swappable : public __conditional_t<__libcpp_is_referenceable<_Tp>::value,
	is_nothrow_swappable_with<__add_lvalue_reference_t<_Tp>, __add_lvalue_reference_t<_Tp> >,
	false_type> {};

template <class _Tp, class _Up>
inline constexpr bool is_swappable_with_v = is_swappable_with<_Tp, _Up>::value;

template <class _Tp>
inline constexpr bool is_swappable_v = is_swappable<_Tp>::value;

template <class _Tp, class _Up>
inline constexpr bool is_nothrow_swappable_with_v = is_nothrow_swappable_with<_Tp, _Up>::value;

template <class _Tp>
inline constexpr bool is_nothrow_swappable_v = is_nothrow_swappable<_Tp>::value;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_SWAPPABLE_HPP__
