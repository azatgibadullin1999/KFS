/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movable.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:53:02 by larlena           #+#    #+#             */
/*   Updated: 2024/05/31 19:31:30 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___CONCEPTS_MOVABLE_HPP__
# define __KFS_OWN_LIBCXX___CONCEPTS_MOVABLE_HPP__

#include <__concepts/assignable.hpp>
#include <__concepts/constructible.hpp>
#include <__concepts/swappable.hpp>
#include <__type_traits/is_object.hpp>

namespace std {

template <class _Tp>
concept movable =
	is_object_v<_Tp> &&
	move_constructible<_Tp> &&
	assignable_from<_Tp&, _Tp> &&
	swappable<_Tp>;

}

#endif // __KFS_OWN_LIBCXX___CONCEPTS_MOVABLE_HPP__
