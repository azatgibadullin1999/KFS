/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cv.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:12:58 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_ADD_CV_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_ADD_CV_HPP__

namespace std {

template <class _Tp>
struct add_cv {
	typedef const volatile _Tp type;
};

template <class _Tp>
using add_cv_t = typename add_cv<_Tp>::type;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_ADD_CV_HPP__
