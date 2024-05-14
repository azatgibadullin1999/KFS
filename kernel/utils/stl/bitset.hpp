/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitset.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:53:52 by larlena           #+#    #+#             */
/*   Updated: 2024/05/14 22:22:39 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_UTILS_STL_BITSET_HPP__
# define __KFS_KERNEL_UTILS_STL_BITSET_HPP__

# include <stddef.h>
# include "array.hpp"
namespace ktl {

template <size_t N>
class bitset {
public:
	class reference {
	public:
		constexpr reference(uint8_t &_byte, uint8_t _mask) noexcept : byte(_byte), mask(_mask) { }

		constexpr operator bool() const noexcept {
			return byte & mask;
		}

		constexpr reference	&operator = (bool x) noexcept {
			if (x) {
				byte |= mask;
			} else {
				byte &= ~mask;
			}
			return *this;
		}

		constexpr reference	&operator = (const reference &x) noexcept {
			return *this = bool(x);
		}

		constexpr void	flip() noexcept {
			byte ^= mask;
		}
	private:
		uint8_t	&byte;
		uint8_t	mask;
	};

	constexpr bitset() noexcept : data() { }

	constexpr reference	operator [] (size_t pos) noexcept {
		return reference(data[pos / 8], bitmask[pos % 8]);
	}

private:
	ktl::array<uint8_t, N / 8>		data;
	static constexpr ktl::array<uint8_t, 8>	bitmask = {
		0b00000001,
		0b00000010,
		0b00000100,
		0b00001000,
		0b00010000,
		0b00100000,
		0b01000000,
		0b10000000
	};
};

}

#endif // __KFS_KERNEL_UTILS_STL_BITSET_HPP__