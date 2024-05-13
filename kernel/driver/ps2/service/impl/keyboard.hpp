/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:02:21 by larlena           #+#    #+#             */
/*   Updated: 2024/05/13 15:42:48 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KERNEL_DRIVER_PS2_SERVICE_IMPL_KEYBOARD_HPP__
# define __KERNEL_DRIVER_PS2_SERVICE_IMPL_KEYBOARD_HPP__

# include <stdint.h>
# include "driver/utils/port.hpp"
# include "driver/common_interface/keyboard.hpp"

namespace kfs::driver::ps2 {

class Keyboard : public kfs::driver::interface::IKeyboard {
public:
	Keyboard() :
		IKeyboard(),
		mPort(0x60) { }

	uint8_t	read() override;
private:
	kfs::driver::utils::PortByte	mPort;
};

}

#endif // __KERNEL_DRIVER_PS2_SERVICE_IMPL_KEYBOARD_HPP__
