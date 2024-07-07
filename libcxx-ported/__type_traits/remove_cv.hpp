/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_cv.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:38:22 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:32:05 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_REMOVE_CV_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_REMOVE_CV_HPP__

# include <__type_traits/remove_const.hpp>
# include <__type_traits/remove_volatile.hpp>

namespace std {

# if __has_builtin(__remove_cv) && !defined(_LIBCPP_COMPILER_GCC)

template <class _Tp>
struct remove_cv {
	using type = __remove_cv(_Tp);
};

template <class _Tp>
using __remove_cv_t = __remove_cv(_Tp);

#  else

template <class _Tp>
struct remove_cv {
	typedef __remove_volatile_t<__remove_const_t<_Tp> > type;
};

template <class _Tp>
using __remove_cv_t = __remove_volatile_t<__remove_const_t<_Tp> >;

# endif // __has_builtin(__remove_cv)

template <class _Tp>
using remove_cv_t = __remove_cv_t<_Tp>;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_REMOVE_CV_HPP__
