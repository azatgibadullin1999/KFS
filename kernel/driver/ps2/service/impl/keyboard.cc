/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.cc                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:02:00 by larlena           #+#    #+#             */
/*   Updated: 2024/05/17 20:19:42 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
