/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.cc                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:02:00 by larlena           #+#    #+#             */
/*   Updated: 2024/03/19 17:07:00 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keyboard.hpp"

namespace kfs::driver::ps2 {

uint8_t	Keyboard::read() {
	auto&&	code = mPort.read();
	auto&&	state = code & 0x80;

	code &= ~0x80;
	if (mKeysState[code]) {
		mKeysState[code] = !state;
		return 0xFF;
	}
	if (state) {
		return 0xFF;
	}
	mKeysState[code] = true;
	return mDecoder->scanLowercase(code);
}

} // namespace kfs::bios
