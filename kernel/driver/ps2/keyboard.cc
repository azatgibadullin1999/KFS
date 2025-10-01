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
	auto&&	code = mPort.read();
	auto&&	isReleased = code & 0x80;
	code &= ~0x80;
	if (mKeysState[code]) {
		mKeysState[code] = !isReleased;
		return 0xFF;
	}
	if (isReleased) {
		return 0xFF;
	}
	mKeysState[code] = true;
	if (isKeyPressed(Decoder::LSHFT) || isKeyPressed(Decoder::RSHFT)) {
		return mDecoder.decodeShift(code);
	} else {
		return mDecoder.decode(code);
	}
}

}
