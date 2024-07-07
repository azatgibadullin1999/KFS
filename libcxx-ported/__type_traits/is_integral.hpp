/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:36:47 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_INTEGRAL_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_INTEGRAL_HPP__

# include <__type_traits/integral_constant.hpp>
# include <__type_traits/remove_cv.hpp>

namespace std {

// clang-format off
template <class _Tp> struct __libcpp_is_integral                     { enum { value = 0 }; };
template <>          struct __libcpp_is_integral<bool>               { enum { value = 1 }; };
template <>          struct __libcpp_is_integral<char>               { enum { value = 1 }; };
template <>          struct __libcpp_is_integral<signed char>        { enum { value = 1 }; };
template <>          struct __libcpp_is_integral<unsigned char>      { enum { value = 1 }; };
template <>          struct __libcpp_is_integral<wchar_t>            { enum { value = 1 }; };
template <>          struct __libcpp_is_integral<char8_t>            { enum { value = 1 }; };
template <>          struct __libcpp_is_integral<char16_t>           { enum { value = 1 }; };
template <>          struct __libcpp_is_integral<char32_t>           { enum { value = 1 }; };
template <>          struct __libcpp_is_integral<short>              { enum { value = 1 }; };
template <>          struct __libcpp_is_integral<unsigned short>     { enum { value = 1 }; };
template <>          struct __libcpp_is_integral<int>                { enum { value = 1 }; };
template <>          struct __libcpp_is_integral<unsigned int>       { enum { value = 1 }; };
template <>          struct __libcpp_is_integral<long>               { enum { value = 1 }; };
template <>          struct __libcpp_is_integral<unsigned long>      { enum { value = 1 }; };
template <>          struct __libcpp_is_integral<long long>          { enum { value = 1 }; };
template <>          struct __libcpp_is_integral<unsigned long long> { enum { value = 1 }; };
// template <>          struct __libcpp_is_integral<__int128_t>         { enum { value = 1 }; };
// template <>          struct __libcpp_is_integral<__uint128_t>        { enum { value = 1 }; };
// clang-format on

# if __has_builtin(__is_integral)

template <class _Tp>
struct _LIBCPP_TEMPLATE_VIS is_integral : _BoolConstant<__is_integral(_Tp)> {};

template <class _Tp>
inline constexpr bool is_integral_v = __is_integral(_Tp);

#  else

template <class _Tp>
struct _LIBCPP_TEMPLATE_VIS is_integral : public _BoolConstant<__libcpp_is_integral<__remove_cv_t<_Tp> >::value> {};

template <class _Tp>
inline constexpr bool is_integral_v = is_integral<_Tp>::value;

# endif // __has_builtin(__is_integral)

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_INTEGRAL_HPP__
