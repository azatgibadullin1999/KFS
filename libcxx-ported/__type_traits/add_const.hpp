/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_const.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:09:55 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_ADD_CONST_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_ADD_CONST_HPP__

namespace std {

template <class _Tp>
struct add_const {
	typedef const _Tp type;
};

template <class _Tp>
using add_const_t = typename add_const<_Tp>::type;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_ADD_CONST_HPP__
