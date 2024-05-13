/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 21:37:18 by larlena           #+#    #+#             */
/*   Updated: 2024/05/12 21:52:53 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_UTILS_STL_PAIR_HPP__
# define __KFS_KERNEL_UTILS_STL_PAIR_HPP__

# include "move.hpp"

namespace ktl {

template <typename T1, typename T2>
struct pair {
	typedef T1		first_type;
	typedef T2		second_type;

	first_type		first;
	second_type		second;

	constexpr pair() :
	first(),
	second() { }

	constexpr pair(const first_type &x, const second_type &y) :
	first(x),
	second(y) { }

	template <typename U1, typename U2>
	constexpr pair(U1 &&x, U2 &&y) :
	first(ktl::forward<U1>(x)),
	second(ktl::forward<U2>(y)) { }

	template <typename U1, typename U2>
	constexpr pair(pair<U1, U2> &other) :
	first(other.first),
	second(other.second) { }

	template <typename U1, typename U2>
	constexpr pair(const pair<U1, U2> &other) :
	first(other.first),
	second(other.second) { }

	template <typename U1, typename U2>
	constexpr pair(pair<U1, U2> &&other) :
	first(ktl::forward(other.first)),
	second(ktl::forward(other.second)) { }

	pair(const pair &other) = default;

	pair(pair &&other) = default;

	pair	&operator = (const pair& other) {
		this->first = other.first;
		this->second = other.second;
		return *this;
	}
};

template<typename T1, typename T2>
bool	operator == (const ktl::pair<T1, T2>& lhs, const ktl::pair<T1, T2>& rhs) {
	return (lhs.first == rhs.first) && (lhs.second == rhs.second);
}

template<typename T1, typename T2>
bool	operator != (const ktl::pair<T1, T2>& lhs, const ktl::pair<T1, T2>& rhs) {
	return !(lhs == rhs);
}

template<typename T1, typename T2>
bool	operator < (const ktl::pair<T1, T2>& lhs, const ktl::pair<T1, T2>& rhs) {
	return lhs.first < rhs.first || ((lhs.first == rhs.first) && lhs.second < rhs.second);
}

template<typename T1, typename T2>
bool	operator > (const ktl::pair<T1, T2>& lhs, const ktl::pair<T1, T2>& rhs) {
	return rhs < lhs;
}

template<typename T1, typename T2>
bool	operator <= (const ktl::pair<T1, T2>& lhs, const ktl::pair<T1, T2>& rhs) {
	return !(lhs > rhs);
}

template<typename T1, typename T2>
bool	operator >= (const ktl::pair<T1, T2>& lhs, const ktl::pair<T1, T2>& rhs) {
	return !(lhs < rhs);
}

}

#endif // __KFS_KERNEL_UTILS_STL_PAIR_HPP__
