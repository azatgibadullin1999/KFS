/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicate.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 00:14:36 by larlena           #+#    #+#             */
/*   Updated: 2024/06/01 00:17:38 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___CONCEPTS_PREDICATE_HPP__
# define __KFS_OWN_LIBCXX___CONCEPTS_PREDICATE_HPP__

# include <__concepts/boolean_testable.hpp>
# include <__concepts/invocable.hpp>
# include <__functional/invoke.hpp>

namespace std {

// [concept.predicate]

template <class _Fn, class... _Args>
concept predicate = regular_invocable<_Fn, _Args...> && __boolean_testable<invoke_result_t<_Fn, _Args...>>;

}

#endif // __KFS_OWN_LIBCXX___CONCEPTS_PREDICATE_HPP__
