/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:56:21 by larlena           #+#    #+#             */
/*   Updated: 2024/05/04 18:06:10 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_UTILS_STL_REVERSE_ITERATOR_HPP__
# define __KFS_KERNEL_UTILS_STL_REVERSE_ITERATOR_HPP__

# include "iterator_traits.hpp"

namespace ktl {

template <class Iterator>
class reverse_iterator {
public:
		typedef Iterator							iterator_type;
		typedef typename ktl::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef	typename ktl::iterator_traits<Iterator>::value_type		value_type;
		typedef typename ktl::iterator_traits<Iterator>::reference		reference;
		typedef typename ktl::iterator_traits<Iterator>::pointer		pointer;
		typedef	typename ktl::iterator_traits<Iterator>::difference_type	difference_type;

protected:
	iterator_type	mIter;

public:

		reverse_iterator() : mIter(nullptr) { }

		explicit reverse_iterator(iterator_type other) : mIter(other) { }

		template <class InputIt>
		reverse_iterator(const reverse_iterator<InputIt>& other) : mIter(other.base()) { }

		template <class InputIt>
		reverse_iterator	&operator = (const reverse_iterator<InputIt>& other) {
			mIter = other.base();
			return *this;
		}

		iterator_type	base() const {
			return mIter;
		}

		reference	operator * () const {
			iterator_type	tmp = mIter;
			// --tmp;
			return *--tmp;
		}

		pointer		operator -> () const {
			iterator_type	tmp = mIter;
			// --tmp;
			return --tmp.operator->();
		}

		reference	operator [] (difference_type n) const {
			return *(*this + n);
		}

		reverse_iterator	&operator ++ () {
			--mIter;
			return *this;
		}

		reverse_iterator	&operator -- () {
			++mIter;
			return *this;
		}

		reverse_iterator	operator ++ (int) {
			reverse_iterator	dst = *this;
			--mIter;
			return dst;
		}

		reverse_iterator	operator -- (int) {
			reverse_iterator	dst = *this;
			++mIter;
			return dst;
		}

		reverse_iterator	operator + (difference_type n) const {
			reverse_iterator	dst = *this;
			dst._iter -= n;
			return dst;
		}

		reverse_iterator	operator - (difference_type n) const {
			reverse_iterator	dst = *this;
			dst._iter += n;
			return dst;
		}

		reverse_iterator	&operator += (difference_type n) {
			mIter -= n;
			return *this;
		}

		reverse_iterator	&operator -= (difference_type n) {
			mIter += n;
			return *this;
		}
} ;


template <typename T_L, typename T_R>
bool	operator == (const ktl::reverse_iterator<T_L> &lhs, const ktl::reverse_iterator<T_R> &rhs) {
	return lhs.base() == rhs.base();
}

template <typename T_L, typename T_R>
bool	operator != (const ktl::reverse_iterator<T_L> &lhs, const ktl::reverse_iterator<T_R> &rhs) {
	return !(lhs == rhs);
}

template <typename T_L, typename T_R>
bool	operator < (const ktl::reverse_iterator<T_L> &lhs, const ktl::reverse_iterator<T_R> &rhs) {
	return lhs.base() > rhs.base();
}

template <typename T_L, typename T_R>
bool	operator > (const ktl::reverse_iterator<T_L> &lhs, const ktl::reverse_iterator<T_R> &rhs) {
	return rhs < lhs;
}

template <typename T_L, typename T_R>
bool	operator <= (const ktl::reverse_iterator<T_L> &lhs, const ktl::reverse_iterator<T_R> &rhs) {
	return !(lhs > rhs);
}

template <typename T_L, typename T_R>
bool	operator >= (const ktl::reverse_iterator<T_L> &lhs, const ktl::reverse_iterator<T_R> &rhs) {
	return !(lhs < rhs);
}

template <typename Iter>
reverse_iterator<Iter>
operator + (typename ktl::reverse_iterator<Iter>::difference_type n, const ktl::reverse_iterator<Iter> &it) {
	return it + n;
}

template <typename Iter>
typename ktl::reverse_iterator<Iter>::difference_type
operator - (const ktl::reverse_iterator<Iter> &lhs,
			const ktl::reverse_iterator<Iter> &rhs) {
	return rhs.base() - lhs.base();
}

template <typename T_L, typename T_R>
typename ktl::iterator_traits<T_L>::difference_type	operator - (ktl::reverse_iterator<T_L> lhs, ktl::reverse_iterator<T_R> rhs) {
	return rhs.base() - lhs.base();
}


}

#endif // __KFS_KERNEL_UTILS_STL_REVERSE_ITERATOR_HPP__
