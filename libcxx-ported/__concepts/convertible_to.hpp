/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertible_to.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:01:18 by larlena           #+#    #+#             */
/*   Updated: 2024/05/31 19:31:30 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___CONCEPTS_CONVERTIBLE_TO_HPP__
# define __KFS_OWN_LIBCXX___CONCEPTS_CONVERTIBLE_TO_HPP__

#include <__type_traits/is_convertible.hpp>
#include <__utility/declval.hpp>

namespace std {

template <class _From, class _To>
concept convertible_to =
	is_convertible_v<_From, _To> &&
	requires { static_cast<_To>(std::declval<_From>()); };

}

#endif // __KFS_OWN_LIBCXX___CONCEPTS_CONVERTIBLE_TO_HPP__
