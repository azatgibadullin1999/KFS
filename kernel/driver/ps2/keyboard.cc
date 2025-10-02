/**
 * @file keyboard.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "keyboard.hpp"

namespace kfs::driver::ps2 {

uint8_t	Keyboard::read() const {
	auto&&	code = _port.read();
	auto&&	released = code & 0x80;
	code &= ~0x80;
	if (_keys_state[code]) {
		_keys_state[code] = not released;
		return 0xFF;
	}
	if (released) {
		return 0xFF;
	}
	_keys_state[code] = true;
	if (is_key_pressed(Decoder::LSHFT) || is_key_pressed(Decoder::RSHFT)) {
		return _decoder.decode_shift(code);
	}
	return _decoder.decode(code);
}

}
