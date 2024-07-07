/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concepts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 23:22:00 by larlena           #+#    #+#             */
/*   Updated: 2024/06/04 21:21:17 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_UTILS_STL_CONCEPTS_HPP__
# define __KFS_KERNEL_UTILS_STL_CONCEPTS_HPP__

# include <type_traits>

namespace ktl {

template <typename T>
concept destructible =


template <typename T, typename ... Args>
concept constructible_from = 
	

template <typename T>
concept move_constructible =
	std::

template <typename T>
concept movable = 
	std::is_object_v<T> &&


}

#endif __KFS_KERNEL_UTILS_STL_CONCEPTS_HPP__
