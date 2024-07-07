/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exchange.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:01:29 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___UTILITY_EXCHAGE_HPP__
# define __KFS_LIBXX_PORTED___UTILITY_EXCHAGE_HPP__

# include <__type_traits/is_nothrow_assignable.hpp>
# include <__type_traits/is_nothrow_move_constructible.hpp>
# include <__utility/forward.hpp>
# include <__utility/move.hpp>

namespace std {

template <class _T1, class _T2 = _T1>
inline constexpr _T1 exchange(_T1& __obj, _T2&& __new_value) noexcept(
	is_nothrow_move_constructible<_T1>::value && is_nothrow_assignable<_T1&, _T2>::value) {
	_T1 __old_value = std::move(__obj);
	__obj           = std::forward<_T2>(__new_value);
	return __old_value;
}

}

#endif // __KFS_LIBXX_PORTED___UTILITY_EXCHAGE_HPP__
