/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:27:15 by larlena           #+#    #+#             */
/*   Updated: 2024/05/14 21:46:08 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_UTILS_STL_ITERATOR_TRAITS_HPP__
# define __KFS_KERNEL_UTILS_STL_ITERATOR_TRAITS_HPP__

# include <stddef.h>

namespace ktl {

template <class Iter>
struct iterator_traits {
	// typedef typename Iter::iterator_category	iterator_category;
	typedef typename Iter::value_type		value_type;
	typedef typename Iter::difference_type		difference_type;
	typedef typename Iter::reference		reference;
	typedef typename Iter::pointer			pointer;
} ;

template <typename T>
struct iterator_traits<T*> {
	// typedef typename ktl::random_access_iterator_tag	iterator_category;
	typedef T						value_type;
	typedef ptrdiff_t					difference_type;
	typedef T&						reference;
	typedef T*						pointer;							
} ;

template <typename T>
struct iterator_traits<const T*> {
	// typedef typename ktl::random_access_iterator_tag	iterator_category;
	typedef T						value_type;
	typedef ptrdiff_t					difference_type;
	typedef const T&					reference;
	typedef const T*					pointer;							
} ;

}

#endif // __KFS_KERNEL_UTILS_STL_ITERATOR_TRAITS_HPP__
