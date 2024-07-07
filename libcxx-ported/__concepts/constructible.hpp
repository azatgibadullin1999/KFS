/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructible.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:15:50 by larlena           #+#    #+#             */
/*   Updated: 2024/05/31 19:31:30 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___CONCEPTS_CONSTRUCTIBLE_HPP__
# define __KFS_OWN_LIBCXX___CONCEPTS_CONSTRUCTIBLE_HPP__

#include <__concepts/convertible_to.hpp>
#include <__concepts/destructible.hpp>
#include <__type_traits/is_constructible.hpp>

namespace std {

// [concept.constructible]
template <class _Tp, class... _Args>
concept constructible_from =
	destructible<_Tp> &&
	is_constructible_v<_Tp, _Args...>;

// [concept.default.init]

template <class _Tp>
concept __default_initializable =
	requires { ::new _Tp; };

template <class _Tp>
concept default_initializable =
	constructible_from<_Tp> &&
	requires { _Tp{}; } &&
	__default_initializable<_Tp>;

// [concept.moveconstructible]
template <class _Tp>
concept move_constructible =
	constructible_from<_Tp, _Tp> &&
	convertible_to<_Tp, _Tp>;

// [concept.copyconstructible]
// clang-format off
template <class _Tp>
concept copy_constructible =
	move_constructible<_Tp> &&
	constructible_from<_Tp, _Tp&> &&
	convertible_to<_Tp&, _Tp> &&
	constructible_from<_Tp, const _Tp&> &&
	convertible_to<const _Tp&, _Tp> &&
	constructible_from<_Tp, const _Tp> &&
	convertible_to<const _Tp, _Tp>;
// clang-format on

}

#endif // __KFS_OWN_LIBCXX___CONCEPTS_CONSTRUCTIBLE_HPP__
