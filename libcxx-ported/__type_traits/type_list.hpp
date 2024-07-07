/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_list.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:43:46 by larlena           #+#    #+#             */
/*   Updated: 2024/06/04 11:45:34 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___TYPE_TRAITS_TYPE_LIST_HPP__
# define __KFS_OWN_LIBCXX___TYPE_TRAITS_TYPE_LIST_HPP__

# include <cstddef>

namespace std {

template <class _Hp, class _Tp>
struct __type_list {
	typedef _Hp _Head;
	typedef _Tp _Tail;
};

template <class _TypeList, size_t _Size, bool = _Size <= sizeof(typename _TypeList::_Head)>
struct __find_first;

template <class _Hp, class _Tp, size_t _Size>
struct __find_first<__type_list<_Hp, _Tp>, _Size, true> {
	typedef _Hp type;
};

template <class _Hp, class _Tp, size_t _Size>
struct __find_first<__type_list<_Hp, _Tp>, _Size, false> {
	typedef typename __find_first<_Tp, _Size>::type type;
};

}

#endif // __KFS_OWN_LIBCXX___TYPE_TRAITS_TYPE_LIST_HPP__
