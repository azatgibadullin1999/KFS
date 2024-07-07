/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_all_extents.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:25:52 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_REMOVE_ALL_EXTENTS_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_REMOVE_ALL_EXTENTS_HPP__

# include <cstddef>

namespace std {

# if __has_builtin(__remove_all_extents)

template <class _Tp>
struct remove_all_extents {
	using type = __remove_all_extents(_Tp);
};

template <class _Tp>
using __remove_all_extents_t = __remove_all_extents(_Tp);

#  else

template <class _Tp>
struct remove_all_extents {
	typedef _Tp type;
};
template <class _Tp>
struct remove_all_extents<_Tp[]> {
	typedef typename remove_all_extents<_Tp>::type type;
};
template <class _Tp, size_t _Np>
struct remove_all_extents<_Tp[_Np]> {
	typedef typename remove_all_extents<_Tp>::type type;
};

template <class _Tp>
using __remove_all_extents_t = typename remove_all_extents<_Tp>::type;

# endif // __has_builtin(__remove_all_extents)

template <class _Tp>
using remove_all_extents_t = __remove_all_extents_t<_Tp>;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_REMOVE_ALL_EXTENTS_HPP__
