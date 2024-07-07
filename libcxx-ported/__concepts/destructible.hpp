/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructible.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:19:01 by larlena           #+#    #+#             */
/*   Updated: 2024/05/31 19:31:30 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___CONCEPTS_DESTRUCTIBLE_HPP__
# define __KFS_OWN_LIBCXX___CONCEPTS_DESTRUCTIBLE_HPP__

#include <__type_traits/is_nothrow_destructible.hpp>

namespace std {

// [concept.destructible]

template <class _Tp>
concept destructible =
	is_nothrow_destructible_v<_Tp>;

}

#endif // __KFS_OWN_LIBCXX___CONCEPTS_DESTRUCTIBLE_HPP__
