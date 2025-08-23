/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_first_not_of_own.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 17:44:19 by larlena           #+#    #+#             */
/*   Updated: 2024/06/07 17:48:37 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_LIBCXX_LLVM_PORTED___ALHORITHM_FIND_FIRST_NOT_OF_OWN_HPP__
# define __KFS_LIBCXX_LLVM_PORTED___ALHORITHM_FIND_FIRST_NOT_OF_OWN_HPP__

# include <__algorithm/find.h>
# include <__algorithm/find_if.h>

namespace ktl {

template <typename ForwardIt1, typename ForwardIt2>
ForwardIt1	find_first_not_of(ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last) {
	for (; first != last; ++first) {
		if (std::find(s_first, s_last, *first) == s_last) {
			return first;
		}
	}
	return last;
}

template <typename ForwardIt1, typename ForwardIt2, typename BinaryPred>
ForwardIt1	find_first_not_of(ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last, BinaryPred p) {
	for (; first != last; ++first) {
		if (std::find_if(s_first, s_last, p) == s_last) {
			return first;
		}
	}
	return last;
}

}

#endif // __KFS_LIBCXX_LLVM_PORTED___ALHORITHM_FIND_FIRST_NOT_OF_OWN_HPP__
