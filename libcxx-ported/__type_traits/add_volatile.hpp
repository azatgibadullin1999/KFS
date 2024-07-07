/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_volatile.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:11:24 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_ADD_CONST_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_ADD_CONST_HPP__

namespace std {

template <class _Tp>
struct add_volatile {
	typedef volatile _Tp type;
};

template <class _Tp>
using add_volatile_t = typename add_volatile<_Tp>::type;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_ADD_CONST_HPP__
