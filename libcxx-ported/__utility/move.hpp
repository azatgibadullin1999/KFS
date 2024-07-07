/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:14:03 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:38:11 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___UTILITY_MOVE_HPP__
# define __KFS_LIBXX_PORTED___UTILITY_MOVE_HPP__

#include <__type_traits/conditional.hpp>
#include <__type_traits/is_copy_constructible.hpp>
#include <__type_traits/is_nothrow_move_constructible.hpp>
#include <__type_traits/remove_reference.hpp>


namespace std {

template <class _Tp>
[[nodiscard]] inline constexpr __libcpp_remove_reference_t<_Tp>&& move(_Tp&& __t) noexcept {
	typedef __libcpp_remove_reference_t<_Tp> _Up;
	return static_cast<_Up&&>(__t);
}

template <class _Tp>
using __move_if_noexcept_result_t =
	__conditional_t<!is_nothrow_move_constructible<_Tp>::value && is_copy_constructible<_Tp>::value, const _Tp&, _Tp&&>;

template <class _Tp>
[[nodiscard]] inline constexpr __move_if_noexcept_result_t<_Tp> move_if_noexcept(_Tp& __x) noexcept {
	return std::move(__x);
}

}

#endif // __KFS_LIBXX_PORTED___UTILITY_MOVE_HPP__
