/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:19:54 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___UTILITY_SWAP_HPP__
# define __KFS_LIBXX_PORTED___UTILITY_SWAP_HPP__

# include <__type_traits/is_move_assignable.hpp>
# include <__type_traits/is_move_constructible.hpp>
# include <__type_traits/is_nothrow_move_assignable.hpp>
# include <__type_traits/is_nothrow_move_constructible.hpp>
# include <__type_traits/is_swappable.hpp>
# include <__utility/declval.hpp>
# include <__utility/move.hpp>
# include <cstddef>

namespace std {

template <class _Tp>
inline constexpr void swap(_Tp& __x, _Tp& __y) noexcept(is_nothrow_move_constructible<_Tp>::value&& is_nothrow_move_assignable<_Tp>::value) {
	_Tp __t(std::move(__x));
	__x = std::move(__y);
	__y = std::move(__t);
}

template <class _Tp, size_t _Np, __enable_if_t<__is_swappable<_Tp>::value, int> >
inline constexpr void swap(_Tp (&__a)[_Np], _Tp (&__b)[_Np]) noexcept(__is_nothrow_swappable<_Tp>::value) {
	for (size_t __i = 0; __i != _Np; ++__i) {
		swap(__a[__i], __b[__i]);
	}
}

}

#endif // __KFS_LIBXX_PORTED___UTILITY_SWAP_HPP__
