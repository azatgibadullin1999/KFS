/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_decoder.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:06:44 by larlena           #+#    #+#             */
/*   Updated: 2024/03/27 18:21:13 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_COMMON_INTERFACE_KEYBOARD_DECODER_HPP__
# define __KFS_KERNEL_DRIVER_COMMON_INTERFACE_KEYBOARD_DECODER_HPP__

# include <stdint.h>
# include "keyboard.hpp"

namespace kfs::driver::interface {

class IKeyboardDecoder {
public:
	IKeyboardDecoder(kfs::driver::interface::IKayboard *keyboard) :
	mKeyboard(keyboard) { }
	
	virtual uint8_t	scan(const uint8_t &code) const = 0;

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
	kfs::driver::interface::IKayboard	*mKeyboard;
};

}

#endif // __KFS_KERNEL_DRIVER_COMMON_INTERFACE_KEYBOARD_DECODER_HPP__
