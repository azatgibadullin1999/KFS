/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kayboard.cc                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:02:00 by larlena           #+#    #+#             */
/*   Updated: 2024/04/14 10:44:26 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kayboard.hpp"

namespace kfs::driver::ps2 {

uint8_t	Kayboard::read() {
	auto&&	code = mPort.read();
	auto&&	state = code & 0x80;

	code &= ~0x80;
	if (isPressed(code)) {
		mKaysState[code] = !state;
		return 0xFF;
	}
	if (state) {
		return 0xFF;
	}
	mKaysState[code] = true;
	return code;
}

}
