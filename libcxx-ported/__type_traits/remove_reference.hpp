/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_reference.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:47:21 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:34:00 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_REMOVE_REFERENCE_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_REMOVE_REFERENCE_HPP__

# include <cstddef>


namespace std {

# if __has_builtin(__remove_reference_t)

template <class _Tp>
struct remove_reference {
	using type = __remove_reference_t(_Tp);
};

template <class _Tp>
using __libcpp_remove_reference_t = __remove_reference_t(_Tp);

#  else

// clang-format off
template <class _Tp> struct remove_reference        {typedef _Tp type;};
template <class _Tp> struct remove_reference<_Tp&>  {typedef _Tp type;};
template <class _Tp> struct remove_reference<_Tp&&> {typedef _Tp type;};
// clang-format on

template <class _Tp>
using __libcpp_remove_reference_t = typename remove_reference<_Tp>::type;

# endif // __has_builtin(__remove_reference_t)

template <class _Tp>
using remove_reference_t = __libcpp_remove_reference_t<_Tp>;

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_REMOVE_REFERENCE_HPP__
