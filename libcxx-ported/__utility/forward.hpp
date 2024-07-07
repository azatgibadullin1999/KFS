/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:26:00 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___UTILITY_FORWARD_HPP__
# define __KFS_LIBXX_PORTED___UTILITY_FORWARD_HPP__

# include <__type_traits/is_reference.hpp>
# include <__type_traits/remove_reference.hpp>

namespace std {

template <class _Tp>
[[nodiscard]] inline constexpr _Tp&& forward(__libcpp_remove_reference_t<_Tp>& __t) noexcept {
	return static_cast<_Tp&&>(__t);
}

template <class _Tp>
[[nodiscard]] inline constexpr _Tp&& forward(__libcpp_remove_reference_t<_Tp>&& __t) noexcept {
	static_assert(!is_lvalue_reference<_Tp>::value, "cannot forward an rvalue as an lvalue");
	return static_cast<_Tp&&>(__t);
}


}

#endif // __KFS_LIBXX_PORTED___UTILITY_FORWARD_HPP__
