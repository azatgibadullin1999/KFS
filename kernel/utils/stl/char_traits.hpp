/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:42:24 by larlena           #+#    #+#             */
/*   Updated: 2024/05/11 11:54:56 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_UTILS_STL_CHAR_TRAITS_HPP__
# define __KFS_KERNEL_UTILS_STL_CHAR_TRAITS_HPP__

# include <stddef.h>
# include "utils/libft.hpp"
# include "algorithm.hpp"

# define _CHAR_TRAITS_EOF (-1)

namespace ktl {

template <typename CharT>
struct char_traits {
	typedef	CharT		char_type;
	typedef unsigned int	int_type;

	static void	assign(char_type &c1, const char_type &c2) {
		c1 = c2;
	}

	static bool	eq(const char_type &c1, const char_type &c2) {
		return c1 == c2;
	}

	static bool	lt(const char_type &c1, const char_type &c2) {
		return c1 < c2;
	}

	static char_type	*move(char_type *s1, const char_type *s2, size_t n) {
		return static_cast<char_type*>(kfs::memmove(s1, s2, n * sizeof(char_type)));
	}

	static char_type	*copy(char_type *s1, const char_type *s2, size_t n) {
		return static_cast<char_type*>(ktl::copy(s2, s2 + n, s1));
	}

	static int	compare(const char_type *s1, const char_type *s2, size_t n) {
		for (size_t i = 0; i < n; ++i) {
			if (lt(s1[i], s2[i])) {
				return -1;
			} else if (lt(s2[i], s1[i])) {
				return 1;
			}
		}
		return 0;
	}

	static size_t	length(const char_type *s) {
		size_t	i;

		for (i = 0; s[i]; ++i) { }
		return i;
	}

	static const char_type	*find(const char_type *s, size_t n, const char_type &a) {
		for (size_t i = 0; i < n; ++i) {
			if (eq(s[i], a)) {
				return s;
			}
		}
		return 0;
	}

	static char_type	to_char_type(const int_type &c) {
		return static_cast<char_type>(c);
	}

	static int_type		to_int_type(const char_type &c) {
		return static_cast<int_type>(c);
	}
	
	static bool		eq_int_type(const int_type &c1, const int_type &c2) {
		return c1 == c2;
	}

	static int_type		eof() {
		return static_cast<int_type>(_CHAR_TRAITS_EOF);
	}

	static int_type		not_eof(const int_type &c) {
		return eq_int_type(c, eof()) ? 0 : c;
	}
};

}

#endif // __KFS_KERNEL_UTILS_STL_CHAR_TRAITS_HPP__
