/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invocable.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:06:56 by larlena           #+#    #+#             */
/*   Updated: 2024/06/01 00:12:42 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___CONCEPTS_INVOCABLE_HPP__
# define __KFS_OWN_LIBCXX___CONCEPTS_INVOCABLE_HPP__

# include <__functional/invoke.hpp>
# include <__utility/forward.hpp>

namespace std {

// [concept.invocable]

template <class _Fn, class... _Args>
concept invocable = requires(_Fn&& __fn, _Args&&... __args) {
	std::invoke(std::forward<_Fn>(__fn), std::forward<_Args>(__args)...); // not required to be equality preserving
};

// [concept.regular.invocable]

template <class _Fn, class... _Args>
concept regular_invocable = invocable<_Fn, _Args...>;

}

#endif // __KFS_OWN_LIBCXX___CONCEPTS_INVOCABLE_HPP__