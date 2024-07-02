/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 22:49:33 by larlena           #+#    #+#             */
/*   Updated: 2024/05/14 21:52:31 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_UTILS_STL_ARRAY_HPP__
# define __KFS_KERNEL_UTILS_STL_ARRAY_HPP__

# include <stddef.h>
# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"
# include "algorithm.hpp"

namespace ktl {

template <typename T, size_t N>
class array {
public:
	typedef T					value_type;
	typedef size_t					size_type;
	typedef ptrdiff_t				difference_type;
	typedef value_type&				reference;
	typedef const value_type&			const_reference;
	typedef value_type*				pointer;
	typedef const value_type*			const_pointer;
	typedef value_type*				iterator;
	typedef const value_type*			const_iterator;
	typedef ktl::reverse_iterator<iterator>		reverse_iterator;
	typedef ktl::reverse_iterator<const_iterator>	const_reverse_iterator;

	value_type	mArray[N];

	reference	operator [] (size_type pos) {
		return mArray[pos];
	}

	const_reference	operator [] (size_type pos) const {
		return mArray[pos];
	}

	reference	front() {
		return mArray[0];
	}

	const_reference	front() const {
		return mArray[0];
	}

	reference	back() {
		return mArray[N - 1];
	}

	const_reference	back() const {
		return mArray[N - 1];
	}

	pointer		data() {
		return mArray;
	}

	const_pointer	data() const {
		return mArray;
	}

	iterator	begin() {
		return mArray;
	}

	const_iterator begin() const {
		return mArray;
	}

	const_iterator	cbegin() const {
		return mArray;
	}

	iterator	end() {
		return &mArray[N];
	}

	const_iterator	end() const {
		return &mArray[N];
	}

	const_iterator	cend() const {
		return &mArray[N];
	}
	
	constexpr size_type	size() const {
		return N;
	}
};

template <typename T, size_t N>
bool	operator == (const array<T, N> &lhs, const array<T, N> &rhs) {
	return ktl::equal(lhs.begin(), lhs.end(), rhs.begin()) && (lhs.size() == rhs.size());
}

template <typename T, size_t N>
bool	operator != (const array<T, N> &lhs, const array<T, N> &rhs) {
	return !(lhs == rhs);
}

template <typename T, size_t N>
bool	operator < (const array<T, N> &lhs, const array<T, N> &rhs) {
	return ktl::lexicographic_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename T, size_t N>
bool	operator > (const array<T, N> &lhs, const array<T, N> &rhs) {
	return (rhs < lhs);
}

template <typename T, size_t N>
bool	operator >= (const array<T, N> &lhs, const array<T, N> &rhs) {
	return !(lhs < rhs);
}

template <typename T, size_t N>
bool	operator <= (const array<T, N> &lhs, const array<T, N> &rhs) {
	return !(lhs > rhs);
}

}

#endif // __KFS_KERNEL_UTILS_STL_ARRAY_HPP__