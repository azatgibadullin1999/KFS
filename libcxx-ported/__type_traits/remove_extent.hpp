/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_extent.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:00:00 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_EXTENT_HPP__
# define __KFS_LIBXX_PORTED___TYPE_EXTENT_HPP__

#include <cstddef>

namespace std {

# if __has_builtin(__remove_extent)

template <class _Tp>
struct remove_extent {
	using type = __remove_extent(_Tp);
};

template <class _Tp>
using __remove_extent_t = __remove_extent(_Tp);

#  else

template <class _Tp>
struct remove_extent {
	typedef _Tp type;
};
template <class _Tp>
struct remove_extent<_Tp[]> {
	typedef _Tp type;
};
template <class _Tp, size_t _Np>
struct remove_extent<_Tp[_Np]> {
	typedef _Tp type;
};

template <class _Tp>
using __remove_extent_t = typename remove_extent<_Tp>::type;

# endif // __has_builtin(__remove_extent)

template <class _Tp>
using remove_extent_t = __remove_extent_t<_Tp>;

}

#endif // __KFS_LIBXX_PORTED___TYPE_EXTENT_HPP__
