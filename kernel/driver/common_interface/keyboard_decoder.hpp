/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_decoder.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:06:44 by larlena           #+#    #+#             */
/*   Updated: 2024/03/19 19:22:57 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_COMMON_INTERFACE_KEYBOARD_DECODER_HPP__
# define __KFS_KERNEL_DRIVER_COMMON_INTERFACE_KEYBOARD_DECODER_HPP__

# include <stdint.h>

namespace kfs::driver::interface {

class IKeyboardDecoder {
public:
	~IKeyboardDecoder() { }
	virtual uint8_t	scanLowercase(const uint8_t &code) const = 0;
	virtual uint8_t	scanUppercase(const uint8_t &code) const = 0;

	static const uint8_t UNKNOWN = 0xFF;
	static const uint8_t ESC = 0xFF - 1;
	static const uint8_t CTRL = 0xFF - 2;
	static const uint8_t LSHFT = 0xFF - 3;
	static const uint8_t RSHFT = 0xFF - 4;
	static const uint8_t ALT = 0xFF - 5;
	static const uint8_t F1 = 0xFF - 6;
	static const uint8_t F2 = 0xFF - 7;
	static const uint8_t F3 = 0xFF - 8;
	static const uint8_t F4 = 0xFF - 9;
	static const uint8_t F5 = 0xFF - 10;
	static const uint8_t F6 = 0xFF - 11;
	static const uint8_t F7 = 0xFF - 12;
	static const uint8_t F8 = 0xFF - 13;
	static const uint8_t F9 = 0xFF - 14;
	static const uint8_t F10 = 0xFF - 15;
	static const uint8_t F11 = 0xFF - 16;
	static const uint8_t F12 = 0xFF - 17;
	static const uint8_t SCRLCK = 0xFF - 18;
	static const uint8_t HOME = 0xFF - 19;
	static const uint8_t UP = 0xFF - 20;
	static const uint8_t LEFT = 0xFF - 21;
	static const uint8_t RIGHT = 0xFF - 22;
	static const uint8_t DOWN = 0xFF - 23;
	static const uint8_t PGUP = 0xFF - 24;
	static const uint8_t PGDOWN = 0xFF - 25;
	static const uint8_t END = 0xFF - 26;
	static const uint8_t INS = 0xFF - 27;
	static const uint8_t DEL = 0xFF - 28;
	static const uint8_t CAPS = 0xFF - 29;
	static const uint8_t NONE = 0xFF - 30;
	static const uint8_t ALTGR = 0xFF - 31;
	static const uint8_t NUMLCK = 0xFF - 32;
};

}

#endif // __KFS_KERNEL_DRIVER_COMMON_INTERFACE_KEYBOARD_DECODER_HPP__