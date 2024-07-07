/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_t.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:05:14 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_VOID_T_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_VOID_T_HPP__

namespace std {

template <class...>
using void_t = void;

template <class...>
using __void_t = void;


}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_VOID_T_HPP__
