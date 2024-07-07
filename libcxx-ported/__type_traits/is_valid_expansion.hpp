/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_expansion.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:38:35 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 12:15:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_VALID_EXPANSION_HPP__
# define __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_VALID_EXPANSION_HPP__

# include <__type_traits/integral_constant.hpp>

namespace std {

template <template <class...> class _Templ, class... _Args, class = _Templ<_Args...> >
true_type __sfinae_test_impl(int);
template <template <class...> class, class...>
false_type __sfinae_test_impl(...);

template <template <class...> class _Templ, class... _Args>
using _IsValidExpansion = decltype(std::__sfinae_test_impl<_Templ, _Args...>(0));

}

#endif // __KFS_LIBXX_PORTED___TYPE_TRAITS_IS_VALID_EXPANSION_HPP__
