/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:42:09 by larlena           #+#    #+#             */
/*   Updated: 2024/05/17 20:07:24 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_COMMON_INTERFACE_KEYBOARD__
# define __KFS_KERNEL_DRIVER_COMMON_INTERFACE_KEYBOARD__

# include <stdint.h>
# include "utils/libft.hpp"
# include "utils/stl/move.hpp"
# include "utils/stl/array.hpp"
# include "utils/stl/bitset.hpp"

namespace kfs::driver::interface {

class IKeyboard {
public:
	class Decoder {
	public:
		using container = ktl::array<uint8_t, 128>;

		constexpr Decoder(container &&keyMap, container &&shiftKeyMap) :
		mKeyMap(ktl::move(keyMap)),
		mShiftKeyMap(ktl::move(shiftKeyMap)),
		mBackwardKeyMap() {
			updateBackwardKeyMap();
		}

		constexpr Decoder(Decoder &&other) :
		Decoder(ktl::move(other.mKeyMap), ktl::move(other.mShiftKeyMap)) { }

		uint8_t	decode(const uint8_t &key) const {
			return mKeyMap[key];
		}

		uint8_t	decodeShift(const uint8_t &key) const {
			return mShiftKeyMap[key];
		}

		uint8_t	encode(const uint8_t &code) const {
			return mBackwardKeyMap[code];
		}

		inline static const uint8_t UNKNOWN = 0xFF;
		inline static const uint8_t ESC = 0xFF - 1;
		inline static const uint8_t CTRL = 0xFF - 2;
		inline static const uint8_t LSHFT = 0xFF - 3;
		inline static const uint8_t RSHFT = 0xFF - 4;
		inline static const uint8_t ALT = 0xFF - 5;
		inline static const uint8_t F1 = 0xFF - 6;
		inline static const uint8_t F2 = 0xFF - 7;
		inline static const uint8_t F3 = 0xFF - 8;
		inline static const uint8_t F4 = 0xFF - 9;
		inline static const uint8_t F5 = 0xFF - 10;
		inline static const uint8_t F6 = 0xFF - 11;
		inline static const uint8_t F7 = 0xFF - 12;
		inline static const uint8_t F8 = 0xFF - 13;
		inline static const uint8_t F9 = 0xFF - 14;
		inline static const uint8_t F10 = 0xFF - 15;
		inline static const uint8_t F11 = 0xFF - 16;
		inline static const uint8_t F12 = 0xFF - 17;
		inline static const uint8_t SCRLCK = 0xFF - 18;
		inline static const uint8_t HOME = 0xFF - 19;
		inline static const uint8_t UP = 0xFF - 20;
		inline static const uint8_t LEFT = 0xFF - 21;
		inline static const uint8_t RIGHT = 0xFF - 22;
		inline static const uint8_t DOWN = 0xFF - 23;
		inline static const uint8_t PGUP = 0xFF - 24;
		inline static const uint8_t PGDOWN = 0xFF - 25;
		inline static const uint8_t END = 0xFF - 26;
		inline static const uint8_t INS = 0xFF - 27;
		inline static const uint8_t DEL = 0xFF - 28;
		inline static const uint8_t CAPS = 0xFF - 29;
		inline static const uint8_t NONE = 0xFF - 30;
		inline static const uint8_t ALTGR = 0xFF - 31;
		inline static const uint8_t NUMLCK = 0xFF - 32;
	protected:
		constexpr void	updateBackwardKeyMap() {
			for (uint8_t it = 0; it < sizeof(mKeyMap); ++it) {
				mBackwardKeyMap[mKeyMap[it]] = it;
				mBackwardKeyMap[mShiftKeyMap[it]] = it;
			}
		}

		container		mKeyMap;
		container		mShiftKeyMap;
		ktl::array<uint8_t, 256>	mBackwardKeyMap;
	};
	constexpr IKeyboard(Decoder &&decoder) :
	mDecoder(ktl::move(decoder)) { }

	virtual uint8_t	read() const = 0;

	bool	isKeyPressed(const uint8_t &code) const {
		return mKeysState[mDecoder.encode(code)];
	}
protected:
	mutable ktl::bitset<128>	mKeysState;
	Decoder			mDecoder;
};

}

#endif // __KFS_KERNEL_DRIVER_COMMON_INTERFACE_KEYBOARD__
