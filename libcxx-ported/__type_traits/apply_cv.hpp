/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_cv.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 23:56:21 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_APPLY_CV_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_APPLY_CV_HPP__

# include <__type_traits/is_const.hpp>
# include <__type_traits/is_volatile.hpp>
# include <__type_traits/remove_reference.hpp>

namespace std {

template <class _Tp,
	bool = is_const<__libcpp_remove_reference_t<_Tp> >::value,
	bool = is_volatile<__libcpp_remove_reference_t<_Tp> >::value>

struct __apply_cv_impl {
	template <class _Up>
	using __apply = _Up;
};

template <class _Tp>
struct __apply_cv_impl<_Tp, true, false> {
	template <class _Up>
	using __apply = const _Up;
};

template <class _Tp>
struct __apply_cv_impl<_Tp, false, true> {
	template <class _Up>
	using __apply = volatile _Up;
};

template <class _Tp>
struct __apply_cv_impl<_Tp, true, true> {
	template <class _Up>
	using __apply = const volatile _Up;
};

template <class _Tp>
struct __apply_cv_impl<_Tp&, false, false> {
	template <class _Up>
	using __apply = _Up&;
};

template <class _Tp>
struct __apply_cv_impl<_Tp&, true, false> {
	template <class _Up>
	using __apply = const _Up&;
};

template <class _Tp>
struct __apply_cv_impl<_Tp&, false, true> {
	template <class _Up>
	using __apply = volatile _Up&;
};

template <class _Tp>
struct __apply_cv_impl<_Tp&, true, true> {
	template <class _Up>
	using __apply = const volatile _Up&;
};

template <class _Tp, class _Up>
using __apply_cv_t = typename __apply_cv_impl<_Tp>::template __apply<_Up>;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_APPLY_CV_HPP__
