/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_move.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:46:31 by larlena           #+#    #+#             */
/*   Updated: 2024/06/04 11:49:36 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_OWN_LIBCXX___ITERATOR_ITER_MOVE_HPP__
# define __KFS_OWN_LIBCXX___ITERATOR_ITER_MOVE_HPP__

# include <__concepts/class_or_enum.hpp>
# include <__iterator/iterator_traits.hpp>
# include <__type_traits/is_reference.hpp>
# include <__type_traits/remove_cvref.hpp>
# include <__utility/declval.hpp>
# include <__utility/forward.hpp>
# include <__utility/move.hpp>

namespace std {


// [iterator.cust.move]

namespace ranges {
namespace __iter_move {

void iter_move();

template <class _Tp>
concept __unqualified_iter_move = __class_or_enum<remove_cvref_t<_Tp>> && requires(_Tp&& __t) {
	// NOLINTNEXTLINE(libcpp-robust-against-adl) iter_swap ADL calls should only be made through ranges::iter_swap
	iter_move(std::forward<_Tp>(__t));
};

template <class _Tp>
concept __move_deref = !__unqualified_iter_move<_Tp> && requires(_Tp&& __t) {
	*__t;
	requires is_lvalue_reference_v<decltype(*__t)>;
};

template <class _Tp>
concept __just_deref = !__unqualified_iter_move<_Tp> && !__move_deref<_Tp> && requires(_Tp&& __t) {
	*__t;
	requires(!is_lvalue_reference_v<decltype(*__t)>);
};

// [iterator.cust.move]

struct __fn {

	// NOLINTBEGIN(libcpp-robust-against-adl) iter_move ADL calls should only be made through ranges::iter_move
	template <class _Ip>
		requires __unqualified_iter_move<_Ip>
	[[nodiscard]] constexpr decltype(auto) operator()(_Ip&& __i) const
		noexcept(noexcept(iter_move(std::forward<_Ip>(__i)))) {
		return iter_move(std::forward<_Ip>(__i));
	}
	// NOLINTEND(libcpp-robust-against-adl)

	template <class _Ip>
		requires __move_deref<_Ip>
	[[nodiscard]] constexpr auto operator()(_Ip&& __i) const
		noexcept(noexcept(std::move(*std::forward<_Ip>(__i)))) -> decltype(std::move(*std::forward<_Ip>(__i))) {
		return std::move(*std::forward<_Ip>(__i));
	}

	template <class _Ip>
		requires __just_deref<_Ip>
	[[nodiscard]] constexpr auto operator()(_Ip&& __i) const
		noexcept(noexcept(*std::forward<_Ip>(__i))) -> decltype(*std::forward<_Ip>(__i)) {
		return *std::forward<_Ip>(__i);
	}
};

} // namespace __iter_move

inline namespace __cpo {

inline constexpr auto iter_move = __iter_move::__fn{};

} // namespace __cpo

} // namespace ranges

template <__dereferenceable _Tp>
	requires requires(_Tp& __t) {
		{ ranges::iter_move(__t) } -> __can_reference;
	}
using iter_rvalue_reference_t = decltype(ranges::iter_move(std::declval<_Tp&>()));

}

#endif // __KFS_OWN_LIBCXX___ITERATOR_ITER_MOVE_HPP__
