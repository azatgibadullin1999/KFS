/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:21:20 by larlena           #+#    #+#             */
/*   Updated: 2024/05/17 19:09:46 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_UTILS_STL_TUPLE_HPP__
# define __KFS_KERNEL_UTILS_STL_TUPLE_HPP__

# include <stddef.h>
# include "pair.hpp"
# include "move.hpp"

namespace ktl {

template <size_t I, typename T>
class tuple_element {
public:
	using type = T;
	using value_type = type;
	using reference = value_type&;
	using const_reference = const value_type&;
	using pointer = value_type*;
	using const_pointer = const value_type*;

	tuple_element() = default;
	tuple_element(const tuple_element&) = default;
	tuple_element(tuple_element&&) = default;
	tuple_element	&operator=(const tuple_element&) = default;
	tuple_element	&operator=(tuple_element&&) = default;
	~tuple_element() = default;

	tuple_element(const value_type& value) :
	mValue(value) {}

	tuple_element(value_type&& value) :
	mValue(ktl::move(value)) {}

	tuple_element	&operator=(const value_type& value) {
		mValue = value;
		return *this;
	}

	tuple_element	&operator=(value_type&& value) {
		mValue = ktl::move(value);
		return *this;
	}

	operator value_type&() {
		return mValue;
	}

	operator const value_type&() const {
		return mValue;
	}

	reference	get() {
		return mValue;
	}

	const_reference	get() const {
		return mValue;
	}
private:
	value_type	mValue;
};

template <size_t I, typename T, typename ... Types>
struct extract_type_at {
	using type = typename extract_type_at<I - 1, Types...>::type;
};

template <typename T, typename ... Types>
struct extract_type_at<0, T, Types...> {
	using type = T;
};

template <size_t I, typename ... Types>
class tuple_recursive_base { };

template <size_t I, typename T, typename ... Types>
class tuple_recursive_base<I, T, Types...> :
	public tuple_element<I, typename ktl::remove_reference<T>::type>,
	public tuple_recursive_base<I + 1, Types...> {
public:
	using base_type = tuple_element<I, typename ktl::remove_reference<T>::type>;
	using next_type = tuple_recursive_base<I + 1, Types...>;

	tuple_recursive_base() = default;
	tuple_recursive_base(const T& value, const Types& ... args) :
		base_type(value),
		next_type(args...) {}

	tuple_recursive_base(T&& value, Types&& ... args) :
		base_type(ktl::move(value)),
		next_type(ktl::move(args)...) {}

	tuple_recursive_base(const tuple_recursive_base& other) = default;
	tuple_recursive_base(tuple_recursive_base&& other) = default;

	tuple_recursive_base	&operator=(const tuple_recursive_base& other) = default;
	tuple_recursive_base	&operator=(tuple_recursive_base&& other) = default;
};

template <typename ... Types>
class tuple : public tuple_recursive_base<0, Types...> {
public:
	constexpr tuple() = default;
	constexpr tuple(const Types& ... args) :
	tuple_recursive_base<0, Types...>(args...) { }

	template <typename ... UTypes>
	constexpr tuple(const UTypes& ... args) :
	tuple_recursive_base<0, Types...>(args...) { }

	template <typename ... UTypes>
	constexpr tuple(UTypes&& ... args) :
	tuple_recursive_base<0, Types...>(ktl::move(args)...) { }

	template <typename ... UTypes>
	constexpr tuple(const tuple<UTypes...>&& other);

	template <typename U1, typename U2>
	constexpr tuple(const ktl::pair<U1, U2>& p) :
	tuple_recursive_base<0, U1, U2>(p.first, p.second) { }
	
	template <typename U1, typename U2>
	constexpr tuple(ktl::pair<U1, U2>&& p) :
	tuple_recursive_base<0, U1, U2>(ktl::move(p.first), ktl::move(p.second)) { }

	constexpr tuple(const tuple& other) = default;
	constexpr tuple(tuple&& other) = default;

	tuple	&operator = (const tuple& other) = default;
	tuple	&operator = (tuple&& other) = default;
	
	template <typename ... UTypes>
	tuple	&operator = (const tuple<UTypes...>& other);

	template <typename ... UTypes>
	tuple	&operator = (tuple<UTypes...>&& other);

	template <typename U1, typename U2>
	tuple	&operator = (const ktl::pair<U1, U2>& p);

	template <typename U1, typename U2>
	tuple	&operator = (ktl::pair<U1, U2>&& p);
};


template <typename ... Types>
struct tuple_size { };

template <typename ... Types>
struct tuple_size < ktl::tuple<Types...> > : public ktl::integral_constant<size_t, sizeof...(Types)> { };

template <size_t I, typename ... Types>
auto	&get(ktl::tuple<Types...>& t) noexcept {
	return static_cast<typename ktl::tuple_element<I, typename ktl::extract_type_at<I, Types...>::type>& >(t).get();
}

template <size_t I, typename ... Types>
auto	&get(const ktl::tuple<Types...>& t) noexcept {
	return static_cast<const typename ktl::tuple_element<I, typename ktl::extract_type_at<I, Types...>::type>& >(t).get();
}

template <size_t I, typename ... Args>
bool	compare_tuple(const ktl::tuple<Args...>& lhs, const ktl::tuple<Args...>& rhs) {
	if constexpr (I == 0) {
		return get<I>(lhs) == get<I>(rhs);
	} else {
		return get<I>(lhs) == get<I>(rhs) && compare_tuple<I - 1>(lhs, rhs);
	}
}

template <typename ... T, typename ... U>
bool	operator == (const ktl::tuple<T...>& lhs, const ktl::tuple<U...>& rhs) {
	return compare_tuple<sizeof...(T) - 1>(lhs, rhs);
}

template <typename ... T, typename ... U>
bool	operator != (const ktl::tuple<T...>& lhs, const ktl::tuple<U...>& rhs) {
	return !(lhs == rhs);
}

template <typename ... T, typename ... U>
bool	operator < (const ktl::tuple<T...>& lhs, const ktl::tuple<U...>& rhs) {
	return false;
}

template <typename ... T, typename ... U>
bool	operator > (const ktl::tuple<T...>& lhs, const ktl::tuple<U...>& rhs) {
	return false;
}

template <typename ... T, typename ... U>
bool	operator <= (const ktl::tuple<T...>& lhs, const ktl::tuple<U...>& rhs) {
	return false;
}

template <typename ... T, typename ... U>
bool	operator >= (const ktl::tuple<T...>& lhs, const ktl::tuple<U...>& rhs);

}

#endif // __KFS_KERNEL_UTILS_STL_TUPLE_HPP__
