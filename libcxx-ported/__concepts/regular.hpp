/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regular.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 00:18:24 by larlena           #+#    #+#             */
/*   Updated: 2024/06/01 00:19:24 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___CONCEPTS_REGULAR_HPP__
# define __KFS_OWN_LIBCXX___CONCEPTS_REGULAR_HPP__

# include <__concepts/equality_comparable.hpp>
# include <__concepts/semiregular.hpp>

namespace std {

// [concept.object]

template <class _Tp>
concept regular = semiregular<_Tp> && equality_comparable<_Tp>;

}

#endif // __KFS_OWN_LIBCXX___CONCEPTS_REGULAR_HPP__
