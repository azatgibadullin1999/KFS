/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_type.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:44:34 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_COMMON_TYPE_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_COMMON_TYPE_HPP__

#include <__type_traits/conditional.hpp>
#include <__type_traits/decay.hpp>
#include <__type_traits/is_same.hpp>
#include <__type_traits/remove_cvref.hpp>
#include <__type_traits/void_t.hpp>
#include <__utility/declval.hpp>

namespace std {

// Let COND_RES(X, Y) be:
template <class _Tp, class _Up>
using __cond_type = decltype(false ? std::declval<_Tp>() : std::declval<_Up>());

template <class _Tp, class _Up, class = void>
struct __common_type3 {};

// sub-bullet 4 - "if COND_RES(CREF(D1), CREF(D2)) denotes a type..."
template <class _Tp, class _Up>
struct __common_type3<_Tp, _Up, void_t<__cond_type<const _Tp&, const _Up&>>> {
	using type = remove_cvref_t<__cond_type<const _Tp&, const _Up&>>;
};

template <class _Tp, class _Up, class = void>
struct __common_type2_imp : __common_type3<_Tp, _Up> {};

// sub-bullet 3 - "if decay_t<decltype(false ? declval<D1>() : declval<D2>())> ..."
template <class _Tp, class _Up>
struct __common_type2_imp<_Tp, _Up, __void_t<decltype(true ? std::declval<_Tp>() : std::declval<_Up>())> > {
	typedef __decay_t<decltype(true ? std::declval<_Tp>() : std::declval<_Up>())> type;
};

template <class, class = void>
struct __common_type_impl {};

template <class... _Tp>
struct __common_types;
template <class... _Tp>
struct common_type;

template <class _Tp, class _Up>
struct __common_type_impl< __common_types<_Tp, _Up>, __void_t<typename common_type<_Tp, _Up>::type> > {
	typedef typename common_type<_Tp, _Up>::type type;
};

template <class _Tp, class _Up, class _Vp, class... _Rest>
struct __common_type_impl<__common_types<_Tp, _Up, _Vp, _Rest...>, __void_t<typename common_type<_Tp, _Up>::type> >
	: __common_type_impl<__common_types<typename common_type<_Tp, _Up>::type, _Vp, _Rest...> > {};

// bullet 1 - sizeof...(Tp) == 0

template <>
struct common_type<> {};

// bullet 2 - sizeof...(Tp) == 1

template <class _Tp>
struct common_type<_Tp> : public common_type<_Tp, _Tp> {};

// bullet 3 - sizeof...(Tp) == 2

// sub-bullet 1 - "If is_same_v<T1, D1> is false or ..."
template <class _Tp, class _Up>
struct common_type<_Tp, _Up> : conditional<_IsSame<_Tp, __decay_t<_Tp> >::value && _IsSame<_Up, __decay_t<_Up> >::value,
                  __common_type2_imp<_Tp, _Up>,
                  common_type<__decay_t<_Tp>, __decay_t<_Up> > >::type {};

// bullet 4 - sizeof...(Tp) > 2

template <class _Tp, class _Up, class _Vp, class... _Rest>
struct common_type<_Tp, _Up, _Vp, _Rest...>
	: __common_type_impl<__common_types<_Tp, _Up, _Vp, _Rest...> > {};

template <class... _Tp>
using common_type_t = typename common_type<_Tp...>::type;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_COMMON_TYPE_HPP__
