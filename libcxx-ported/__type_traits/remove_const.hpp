/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_const.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:41:41 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_REMOVE_CONST_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_REMOVE_CONST_HPP__

namespace std {

#if __has_builtin(__remove_const)

template <class _Tp>
struct remove_const {
	using type = __remove_const(_Tp);
};

template <class _Tp>
using __remove_const_t = __remove_const(_Tp);

#else

template <class _Tp>
struct remove_const {
	typedef _Tp type;
};

template <class _Tp>
struct remove_const<const _Tp> {
	typedef _Tp type;
};

template <class _Tp>
using __remove_const_t = typename remove_const<_Tp>::type;

#endif // __has_builtin(__remove_const)

template <class _Tp>
using remove_const_t = __remove_const_t<_Tp>;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_REMOVE_CONST_HPP__
