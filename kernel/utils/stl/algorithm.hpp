/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:03:13 by larlena           #+#    #+#             */
/*   Updated: 2024/05/12 14:58:37 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_UTILS_STL_ALGORITHM_HPP__
# define __KFS_KERNEL_UTILS_STL_ALGORITHM_HPP__

# include "iterator_traits.hpp"

namespace ktl {

template <typename InputIt, typename T>
InputIt	find(InputIt first, InputIt last, const T &value) {
	for (; first != last && !(*first == value); ++first) { }
	return first;
}

template <typename InputIt, typename UnaryPred>
InputIt	find_if(InputIt first, InputIt last, UnaryPred p) {
	for (; first != last && !p(*first); ++first) { }
	return first;
}

template <typename InputIt, typename UnaryPred>
InputIt	find_if_not(InputIt first, InputIt last, UnaryPred q) {
	for (; first != last && q(*first); ++first) { }
	return first;
}

template <typename ForwardIt1, typename ForwardIt2>
ForwardIt1	find_first_of(ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last) {
	for (; first != last; ++first) {
		for (ForwardIt2 it = s_first; it != s_last; ++it) {
			if (*first == *it) {
				return first;
			}
		}
	}
	return last;
}

template <typename ForwardIt1, typename ForwardIt2, typename BinaryPred>
ForwardIt1	find_first_of(ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last, BinaryPred p) {
	for (; first != last; ++first) {
		for (ForwardIt2 it = s_first; it != s_last; ++it) {
			if (p(*first, *it)) {
				return first;
			}
		}
	}
	return last;
}

template <typename ForwardIt1, typename ForwardIt2>
ForwardIt1	find_first_not_of(ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last) {
	for (; first != last; ++first) {
		if (find(s_first, s_last, *first) == s_last) {
			return first;
		}
	}
	return last;
}

template <typename ForwardIt1, typename ForwardIt2, typename BinaryPred>
ForwardIt1	find_first_not_of(ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last, BinaryPred p) {
	for (; first != last; ++first) {
		if (find_if(s_first, s_last, p) == s_last) {
			return first;
		}
	}
	return last;
}


template <typename InputIt, typename OutputIt>
OutputIt	copy(InputIt first, InputIt last, OutputIt d_first) {
	for (; first != last; (void)++first, (void)++d_first) {
		*d_first = *first;
	}
	return d_first;
}

template <typename InputIt, typename OutputIt, typename UnaryPred>
OutputIt	copy_if(InputIt first, InputIt last, OutputIt d_first, UnaryPred pred) {
	for (; first != last; ++first) {
		if (pred(*first)) {
			*d_first = *first;
			++d_first;
		}
	}
	return d_first;
}

template <typename ForwardIt, typename T = typename ktl::iterator_traits<ForwardIt>::value_type>
void fill(ForwardIt first, ForwardIt last, const T& value) {
	for (; first != last; ++first) {
		*first = value;
	}
}

template <typename InputIt1, typename InputIt2>
bool	lexicographic_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2) {
	for (; (first1 != last1) && (first2 != last2); first1++, first2++) {
		if (*first1 < *first2)
			return true;
		if (*first2 < *first1)
			return false;
	}
	return (first1 == last1) && (first2 != last2);
}								

template <typename InputIt1, typename InputIt2, typename Compare>
bool	lexicographic_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp) {
	for (; (first1 != last1) && (first2 != last2); first1++, first2++) {
		if (comp(*first1, *first2))
			return true;
		if (comp(*first2, *first1))
			return false;
	}
	return (first1 == last1) && (first2 != last2);
}

template <typename InputIt1, typename InputIt2>
bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
	for (; first1 != last1; first1++, first2++) {
		if (!(*first1 == *first2))
			return false;
	}
	return true;
}

template <typename InputIt1, typename InputIt2, typename BinaryPredicate>
bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p) {
	for(; first1 != last1; first1++, first2++) {
		if (!p(*first1, first2))
			return false;
	}
	return true;
}

}

#endif // __KFS_KERNEL_UTILS_STL_ALGORITHM_HPP__
