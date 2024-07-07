/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cvref.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:14:30 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_COPY_CVREF_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_COPY_CVREF_HPP__

#include <__type_traits/add_lvalue_reference.hpp>
#include <__type_traits/add_rvalue_reference.hpp>
#include <__type_traits/copy_cv.hpp>

namespace std {

template <class _From, class _To>
struct __copy_cvref {
	using type = __copy_cv_t<_From, _To>;
};

template <class _From, class _To>
struct __copy_cvref<_From&, _To> {
	using type = __add_lvalue_reference_t<__copy_cv_t<_From, _To> >;
};

template <class _From, class _To>
struct __copy_cvref<_From&&, _To> {
	using type = __add_rvalue_reference_t<__copy_cv_t<_From, _To> >;
};

template <class _From, class _To>
using __copy_cvref_t = typename __copy_cvref<_From, _To>::type;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_COPY_CVREF_HPP__
