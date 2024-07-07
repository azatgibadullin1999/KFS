/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:07:36 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_COPY_CV_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_COPY_CV_HPP__

# include <__type_traits/add_const.hpp>
# include <__type_traits/add_cv.hpp>
# include <__type_traits/add_volatile.hpp>

namespace std {

// Let COPYCV(FROM, TO) be an alias for type TO with the addition of FROM's
// top-level cv-qualifiers.
template <class _From, class _To>
struct __copy_cv {
	using type = _To;
};

template <class _From, class _To>
struct __copy_cv<const _From, _To> {
	using type = typename add_const<_To>::type;
};

template <class _From, class _To>
struct __copy_cv<volatile _From, _To> {
	using type = typename add_volatile<_To>::type;
};

template <class _From, class _To>
struct __copy_cv<const volatile _From, _To> {
	using type = typename add_cv<_To>::type;
};

template <class _From, class _To>
using __copy_cv_t = typename __copy_cv<_From, _To>::type;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_COPY_CV_HPP__
