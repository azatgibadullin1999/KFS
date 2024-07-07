/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_signed.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:40:12 by larlena           #+#    #+#             */
/*   Updated: 2024/06/04 11:43:35 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___TYPE_TRAITS_MAKE_SIGNED_HPP__
# define __KFS_OWN_LIBCXX___TYPE_TRAITS_MAKE_SIGNED_HPP__

# include <__type_traits/apply_cv.hpp>
# include <__type_traits/is_enum.hpp>
# include <__type_traits/is_integral.hpp>
# include <__type_traits/nat.hpp>
# include <__type_traits/remove_cv.hpp>
# include <__type_traits/type_list.hpp>

namespace std {

# if __has_builtin(__make_signed)

template <class _Tp>
using __make_signed_t = __make_signed(_Tp);

#  else
// clang-format off
typedef	__type_list<signed char,
	__type_list<signed short,
	__type_list<signed int,
	__type_list<signed long,
	__type_list<signed long long,
// #  ifndef _LIBCPP_HAS_NO_INT128
//         __type_list<__int128_t,
// #  endif
        __nat
// #  ifndef _LIBCPP_HAS_NO_INT128
//         >
// #  endif
        > > > > > __signed_types;
// clang-format on

template <class _Tp, bool = is_integral<_Tp>::value || is_enum<_Tp>::value>
struct __make_signed{};

template <class _Tp>
struct __make_signed<_Tp, true> {
	typedef typename __find_first<__signed_types, sizeof(_Tp)>::type type;
};

// clang-format off
template <> struct __make_signed<bool,               true> {};
template <> struct __make_signed<  signed short,     true> {typedef short     type;};
template <> struct __make_signed<unsigned short,     true> {typedef short     type;};
template <> struct __make_signed<  signed int,       true> {typedef int       type;};
template <> struct __make_signed<unsigned int,       true> {typedef int       type;};
template <> struct __make_signed<  signed long,      true> {typedef long      type;};
template <> struct __make_signed<unsigned long,      true> {typedef long      type;};
template <> struct __make_signed<  signed long long, true> {typedef long long type;};
template <> struct __make_signed<unsigned long long, true> {typedef long long type;};
// #  ifndef _LIBCPP_HAS_NO_INT128
// template <> struct __make_signed<__int128_t,         true> {typedef __int128_t type;};
// template <> struct __make_signed<__uint128_t,        true> {typedef __int128_t type;};
// #  endif
// clang-format on

template <class _Tp>
using __make_signed_t = __apply_cv_t<_Tp, typename __make_signed<__remove_cv_t<_Tp> >::type>;

# endif // __has_builtin(__make_signed)

template <class _Tp>
struct make_signed {
	using type _LIBCPP_NODEBUG = __make_signed_t<_Tp>;
};

template <class _Tp>
using make_signed_t = __make_signed_t<_Tp>;

}

#endif // __KFS_OWN_LIBCXX___TYPE_TRAITS_MAKE_SIGNED_HPP__
