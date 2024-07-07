/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declval.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:53:58 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___UTILITY_DECLVAL_HPP__
# define __KFS_LIBXX_PORTED___UTILITY_DECLVAL_HPP__

# include <__type_traits/add_rvalue_reference.hpp>

namespace ktl {

template<typename T>
typename std::add_rvalue_reference<T>::type declval() noexcept {
	static_assert(false, "declval not allowed in an evaluated context");
}

}

namespace std {

template<typename T>
typename std::add_rvalue_reference<T>::type declval() noexcept {
	static_assert(false, "declval not allowed in an evaluated context");
}

}

#endif // __KFS_LIBXX_PORTED___UTILITY_DECLVAL_HPP__
