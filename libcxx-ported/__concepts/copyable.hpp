/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyable.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:07:14 by larlena           #+#    #+#             */
/*   Updated: 2024/05/31 19:31:30 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___CONCEPTS_COPYABLE_HPP__
# define __KFS_OWN_LIBCXX___CONCEPTS_COPYABLE_HPP__

# include <__concepts/assignable.hpp>
# include <__concepts/constructible.hpp>
# include <__concepts/movable.hpp>

namespace std {

template <class _Tp>
concept copyable =
	copy_constructible<_Tp> &&
	movable<_Tp> &&
	assignable_from<_Tp&, _Tp&> &&
	assignable_from<_Tp&, const _Tp&> &&
	assignable_from<_Tp&, const _Tp>;

}

#endif // __KFS_OWN_LIBCXX___CONCEPTS_COPYABLE_HPP__
