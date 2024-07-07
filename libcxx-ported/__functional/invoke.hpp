/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invoke.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:13:27 by larlena           #+#    #+#             */
/*   Updated: 2024/06/01 00:06:58 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___FUNCTIONAL_INVOKE_HPP__
# define __KFS_OWN_LIBCXX___FUNCTIONAL_INVOKE_HPP__

#include <__type_traits/invoke.hpp>
#include <__utility/forward.hpp>

namespace std {

template <class _Fn, class... _Args>
constexpr invoke_result_t<_Fn, _Args...>
invoke(_Fn&& __f, _Args&&... __args) noexcept(is_nothrow_invocable_v<_Fn, _Args...>) {
	return std::__invoke(std::forward<_Fn>(__f), std::forward<_Args>(__args)...);
}

}

#endif // __KFS_OWN_LIBCXX___FUNCTIONAL_INVOKE_HPP__
