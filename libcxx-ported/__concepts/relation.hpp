/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relation.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 00:22:43 by larlena           #+#    #+#             */
/*   Updated: 2024/06/01 00:23:39 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___CONCEPTS_RELATION_HPP__
# define __KFS_OWN_LIBCXX___CONCEPTS_RELATION_HPP__

# include <__concepts/predicate.hpp>

namespace std {

// [concept.relation]

template <class _Rp, class _Tp, class _Up>
concept relation =
    predicate<_Rp, _Tp, _Tp> && predicate<_Rp, _Up, _Up> && predicate<_Rp, _Tp, _Up> && predicate<_Rp, _Up, _Tp>;

// [concept.equiv]

template <class _Rp, class _Tp, class _Up>
concept equivalence_relation = relation<_Rp, _Tp, _Up>;

// [concept.strictweakorder]

template <class _Rp, class _Tp, class _Up>
concept strict_weak_order = relation<_Rp, _Tp, _Up>;

}

#endif // __KFS_OWN_LIBCXX___CONCEPTS_RELATION_HPP__
