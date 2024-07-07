/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:34:08 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:39:39 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_ENABLE_IF_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_ENABLE_IF_HPP__

namespace std {

template <bool, class _Tp = void>
struct enable_if {};
template <class _Tp>
struct enable_if<true, _Tp> {
	typedef _Tp type;
};

template <bool _Bp, class _Tp = void>
using __enable_if_t = typename enable_if<_Bp, _Tp>::type;

template <bool _Bp, class _Tp = void>
using enable_if_t = typename enable_if<_Bp, _Tp>::type;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_ENABLE_IF_HPP__
