/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:29:59 by larlena           #+#    #+#             */
/*   Updated: 2024/05/14 21:46:08 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_UTILS_STL_ITERATOR_HPP__
# define __KFS_KERNEL_UTILS_STL_ITERATOR_HPP__

# include "iterator_traits.hpp"

namespace ktl {

template <class Iter>
class move_iterator {
	using iterator_type =		Iter;
	using iterator_category =	typename ktl::iterator_traits<Iter>::iterator_category;
	using value_type =		typename ktl::iterator_traits<Iter>::value_type;
	using difference_type =		typename ktl::iterator_traits<Iter>::difference_type;
	using pointer =			typename ktl::iterator_traits<Iter>::pointer;
	using reference =		typename ktl::iterator_traits<Iter>::reference;
	
public:
	move_iterator() noexcept : current() {}
	explicit move_iterator(Iter it) noexcept : current(it) {}
	template <class U>
	move_iterator(const move_iterator<U>& other) noexcept : current(other.base()) {}

	Iter base() const noexcept { return current; }

	reference operator*() const { return ktl::move(*current); }
	pointer operator->() const noexcept { return ktl::addressof(operator*()); }

	move_iterator& operator++() {
		++current;
		return *this;
	}
	
	move_iterator operator++(int) {
		move_iterator tmp = *this;
		++current;
		return tmp;
	}

	move_iterator& operator--() {
		--current;
		return *this;
	}
	
	move_iterator operator--(int) {
		move_iterator tmp = *this;
		--current;
		return tmp;
	}

	move_iterator operator+(difference_type n) const {
		return move_iterator(current + n);
	}
	
	move_iterator& operator+=(difference_type n) {
		current += n;
		return *this;
	}
	
	move_iterator operator-(difference_type n) const {
		return move_iterator(current - n);
	}
	
	move_iterator& operator-=(difference_type n) {
		current -= n;
		return *this;
	}

	reference operator[](difference_type n) const {
		return ktl::move(current[n]);
	}

};
template <class Iter>
bool	operator==(const move_iterator<Iter>& lhs, const move_iterator<Iter>& rhs) {
	return lhs.current == rhs.current;
}
template <class Iter>
bool	operator!=(const move_iterator<Iter>& lhs, const move_iterator<Iter>& rhs) {
	return !(lhs == rhs);
}
template <class Iter>
bool	operator<(const move_iterator<Iter>& lhs, const move_iterator<Iter>& rhs) {
	return lhs.current < rhs.current;
}
template <class Iter>
bool	operator>(const move_iterator<Iter>& lhs, const move_iterator<Iter>& rhs) {
	return rhs < lhs;
}
template <class Iter>
bool	operator<=(const move_iterator<Iter>& lhs, const move_iterator<Iter>& rhs) {
	return !(rhs < lhs);
}
template <class Iter>
bool	operator>=(const move_iterator<Iter>& lhs, const move_iterator<Iter>& rhs) {
	return !(lhs < rhs);
}
template <class Iter>
typename ktl::iterator_traits<Iter>::difference_type	operator-(const move_iterator<Iter>& lhs, const move_iterator<Iter>& rhs) {
	return lhs.current - rhs.current;
}
template <class Iter>
move_iterator<Iter>	operator+(typename move_iterator<Iter>::difference_type n, const move_iterator<Iter>& it) {
	return move_iterator(it.current + n);
}

template <class Iter>
constexpr ktl::move_iterator<Iter>	make_move_iterator(Iter i) {
	return ktl::move_iterator<Iter>(i);
}

} // namespace ktl

#endif // __KFS_KERNEL_UTILS_STL_ITERATOR_HPP__
