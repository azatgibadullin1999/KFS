/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_as.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 01:11:41 by larlena           #+#    #+#             */
/*   Updated: 2024/05/31 19:31:30 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___CONCEPTS_SAME_AS_HPP__
# define __KFS_OWN_LIBCXX___CONCEPTS_SAME_AS_HPP__

# include <__type_traits/is_same.hpp>

namespace std {

template <class _Tp, class _Up>
concept __same_as_impl = _IsSame<_Tp, _Up>::value;

template <class _Tp, class _Up>
concept same_as = __same_as_impl<_Tp, _Up> && __same_as_impl<_Up, _Tp>;


}

#endif // __KFS_OWN_LIBCXX___CONCEPTS_SAME_AS_HPP__
