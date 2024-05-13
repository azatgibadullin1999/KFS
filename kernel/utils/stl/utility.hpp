/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 23:01:39 by larlena           #+#    #+#             */
/*   Updated: 2024/05/26 23:05:25 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_UTILS_STL_UTILITY_HPP__
# define __KFS_KERNEL_UTILS_STL_UTILITY_HPP__

# include "type_traits.hpp"

namespace ktl {

template<typename T>
typename ktl::add_rvalue_reference<T>::type declval() noexcept {
	static_assert(false, "declval not allowed in an evaluated context");
}

} // namespace ktl

#endif // __KFS_KERNEL_UTILS_STL_UTILITY_HPP__
