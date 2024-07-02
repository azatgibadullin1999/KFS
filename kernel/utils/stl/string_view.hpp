/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_view.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:26:08 by larlena           #+#    #+#             */
/*   Updated: 2024/05/12 16:21:14 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_UTILS_STL_STRING_VIEW_HPP__
# define __KFS_KERNEL_UTILS_STL_STRING_VIEW_HPP__

# include "reverse_iterator.hpp"
# include "char_traits.hpp"

namespace ktl {

template <
	typename CharT,
	typename Traits = ktl::char_traits<CharT> >
class basic_string_view {
public:
	using traits_type = Traits;
	using value_type = CharT;
	using pointer = value_type*;
	using const_pointer = const value_type*;
	using reference = value_type&;
	using const_reference = const value_type&;
	using const_iterator = const value_type*;
	using iterator = const_iterator;
	using const_reverse_iterator = ktl::reverse_iterator<const_iterator>;
	using reverse_iterator = const_reverse_iterator;
	using size_type = size_t;
	using difference_type = ptrdiff_t;

	constexpr basic_string_view() :
	mLength(0),
	mString(nullptr) { }

	constexpr basic_string_view(const basic_string_view &other) noexcept = default;

	constexpr basic_string_view(const_pointer str, size_type count) :
	mString(str),
	mLength(count) { }

	constexpr basic_string_view(const_pointer str) :
	mString(str),
	mLength(traits_type::length(str)) { }

	constexpr basic_string_view	&operator = (const basic_string_view &other) noexcept = default;

	constexpr const_iterator	begin() const noexcept {
		return mString;
	}

	constexpr const_iterator	cbegin() const noexcept {
		return mString;
	}

	constexpr const_iterator	end() const noexcept {
		return &mString[mLength];
	}

	constexpr const_iterator	cend() const noexcept {
		return &mString[mLength];
	}

	constexpr const_reverse_iterator	rbegin() const noexcept {
		return reverse_iterator(begin());
	}

	constexpr const_reverse_iterator	crbegin() const noexcept {
		return reverse_iterator(cbegin());
	}

	constexpr const_reverse_iterator	rend() const noexcept {
		return reverse_iterator(end());
	}

	constexpr const_reverse_iterator	crend() const noexcept {
		return reverse_iterator(cend());
	}

	constexpr const_reference	operator [] (size_type pos) const {
		return mString[pos];
	}

	constexpr const_reference	front() const {
		return *mString;
	}

	constexpr const_reference	back() const {
		return mString[mLength - 1];
	}

	constexpr const_pointer		data() const noexcept {
		return mString;
	}
	
	constexpr size_type	size() const noexcept {
		return mLength;
	}

	constexpr size_type	length() const noexcept {
		return mLength;
	}

	const bool	empty() const noexcept {
		return mLength;
	}

private:
	const_pointer	mString;
	size_type	mLength;
};

template <typename CharT, typename Traits>
constexpr bool	operator == (basic_string_view<CharT, Traits> lhs, basic_string_view<CharT, Traits> rhs) noexcept {
	if (lhs.size() != rhs.size()) {
		return 0;
	}
	return !Traits::compare(lhs.data(), rhs.data(), lhs.size());
}

template <typename CharT, typename Traits>
constexpr bool	operator != (basic_string_view<CharT, Traits> lhs, basic_string_view<CharT, Traits> rhs) noexcept {
	return !(lhs == rhs);
}

template <typename CharT, typename Traits>
constexpr bool	operator < (basic_string_view<CharT, Traits> lhs, basic_string_view<CharT, Traits> rhs) noexcept {
	return Traits::compare(lhs.data(), rhs.data(), lhs.size() < rhs.size() ? lhs.size() : rhs.size());
}

template <typename CharT, typename Traits>
constexpr bool	operator > (basic_string_view<CharT, Traits> lhs, basic_string_view<CharT, Traits> rhs) noexcept {
	return rhs < lhs;
}

template <typename CharT, typename Traits>
constexpr bool	operator <= (basic_string_view<CharT, Traits> lhs, basic_string_view<CharT, Traits> rhs) noexcept {
	return !(lhs > rhs);
}

template <typename CharT, typename Traits>
constexpr bool	operator >= (basic_string_view<CharT, Traits> lhs, basic_string_view<CharT, Traits> rhs) noexcept {
	return !(lhs < rhs);
}

using string_view = basic_string_view<char>;

}

#endif // __KFS_KERNEL_UTILS_STL_STRING_VIEW_HPP__
