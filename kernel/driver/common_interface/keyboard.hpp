/**
 * @file keyboard.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef KFS_KERNEL_DRIVER_COMMON_INTERFACE_KEYBOARD_HPP
# define KFS_KERNEL_DRIVER_COMMON_INTERFACE_KEYBOARD_HPP

# include <cstdint>
# include <utility>
# include <array>
# include <bitset>

namespace kfs::driver::interface {

class IKeyboard {
public:
	class Decoder {
	public:
		using container = std::array<uint8_t, 128>;

		constexpr Decoder(container &&key_map, container &&shift_key_map) :
		_key_map(std::move(key_map)),
		_shift_key_map(std::move(shift_key_map)),
		_backward_key_map() {
			_update_backward_key_map();
		}

		constexpr Decoder(Decoder &&other) :
		Decoder(std::move(other._key_map), std::move(other._shift_key_map)) { }

		uint8_t	decode(const uint8_t &key) const {
			return _key_map[key];
		}

		uint8_t	decode_shift(const uint8_t &key) const {
			return _shift_key_map[key];
		}

		uint8_t	encode(const uint8_t &code) const {
			return _backward_key_map[code];
		}

// NOLINTBEGIN
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
// NOLINTEND
	protected:
		constexpr void	_update_backward_key_map() {
			for (uint8_t it = 0; it < sizeof(_key_map); ++it) {
				_backward_key_map[_key_map[it]] = it;
				_backward_key_map[_shift_key_map[it]] = it;
			}
		}

		container		_key_map;
		container		_shift_key_map;
		std::array<uint8_t, 256>	_backward_key_map;
	};
	constexpr IKeyboard(Decoder &&decoder) :
	_decoder(std::move(decoder)) { }

	virtual uint8_t	read() const = 0;

	bool	is_key_pressed(const uint8_t &code) const {
		return _keys_state[_decoder.encode(code)];
	}
protected:
	mutable std::bitset<128>	_keys_state;
	Decoder			_decoder;
};

}

#endif // KFS_KERNEL_DRIVER_COMMON_INTERFACE_KEYBOARD_HPP
