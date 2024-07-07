/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_volatile.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:43:47 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_REMOVE_VOLATILE_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_REMOVE_VOLATILE_HPP__

namespace std {

# if __has_builtin(__remove_volatile)

template <class _Tp>
struct remove_volatile {
	using type = __remove_volatile(_Tp);
};

template <class _Tp>
using __remove_volatile_t = __remove_volatile(_Tp);

#  else

template <class _Tp>
struct remove_volatile {
	typedef _Tp type;
};
template <class _Tp>
struct remove_volatile<volatile _Tp> {
	typedef _Tp type;
};

template <class _Tp>
using __remove_volatile_t = typename remove_volatile<_Tp>::type;

# endif // __has_builtin(__remove_volatile)

template <class _Tp>
using remove_volatile_t = __remove_volatile_t<_Tp>;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_REMOVE_VOLATILE_HPP__
