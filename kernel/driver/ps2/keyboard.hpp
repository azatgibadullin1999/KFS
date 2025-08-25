/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:02:21 by larlena           #+#    #+#             */
/*   Updated: 2025/09/13 16:19:29 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KERNEL_DRIVER_PS2_SERVICE_IMPL_KEYBOARD_HPP__
# define __KERNEL_DRIVER_PS2_SERVICE_IMPL_KEYBOARD_HPP__

# include <stdint.h>
# include "port.hpp"
# include "../common_interface/keyboard.hpp"

namespace kfs::driver::ps2 {

class Keyboard : public kfs::driver::interface::IKeyboard {
public:
	Keyboard(Decoder &&decoder) :
		IKeyboard(std::move(decoder)),
		mPort(0x60) { }

	uint8_t	read() const override;
private:
	kfs::driver::utils::PortByte	mPort;
};

}

#endif // __KERNEL_DRIVER_PS2_SERVICE_IMPL_KEYBOARD_HPP__
