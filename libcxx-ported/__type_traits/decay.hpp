/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decay.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:51:40 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_DECAY_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_DECAY_HPP__

#include <__type_traits/add_pointer.hpp>
#include <__type_traits/conditional.hpp>
#include <__type_traits/is_array.hpp>
#include <__type_traits/is_function.hpp>
#include <__type_traits/is_referenceable.hpp>
#include <__type_traits/remove_cv.hpp>
#include <__type_traits/remove_extent.hpp>
#include <__type_traits/remove_reference.hpp>


namespace std {

#if __has_builtin(__decay)

template <class _Tp>
using __decay_t = __decay(_Tp);

template <class _Tp>
struct decay {
	using type = __decay_t<_Tp>;
};

#else

template <class _Up, bool>
struct __decay {
	typedef __remove_cv_t<_Up> type;
};

template <class _Up>
struct __decay<_Up, true> {
public:
	typedef typename conditional<
		is_array<_Up>::value,
		__add_pointer_t<__remove_extent_t<_Up> >,
		typename conditional<is_function<_Up>::value, typename add_pointer<_Up>::type, __remove_cv_t<_Up> >::type >::type
		type;
};

template <class _Tp>
struct _LIBCPP_TEMPLATE_VIS decay {
private:
	typedef __libcpp_remove_reference_t<_Tp> _Up;

public:
	typedef typename __decay<_Up, __libcpp_is_referenceable<_Up>::value>::type type;
};

template <class _Tp>
using __decay_t = typename decay<_Tp>::type;

#endif // __has_builtin(__decay)

template <class _Tp>
using decay_t = __decay_t<_Tp>;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_DECAY_HPP__
