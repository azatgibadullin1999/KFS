/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_reference_with.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 23:58:55 by larlena           #+#    #+#             */
/*   Updated: 2024/05/31 19:31:30 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___CONCEPTS_COMMON_REFERENCE_WITH_HPP__
# define __KFS_OWN_LIBCXX___CONCEPTS_COMMON_REFERENCE_WITH_HPP__

# include <__concepts/convertible_to.hpp>
# include <__concepts/same_as.hpp>
# include <__type_traits/common_reference.hpp>

namespace std {

template <class _Tp, class _Up>
concept common_reference_with =
	same_as<common_reference_t<_Tp, _Up>, common_reference_t<_Up, _Tp>> &&
	convertible_to<_Tp, common_reference_t<_Tp, _Up>> && convertible_to<_Up, common_reference_t<_Tp, _Up>>;

}

#endif // __KFS_OWN_LIBCXX___CONCEPTS_COMMON_REFERENCE_WITH_HPP__
