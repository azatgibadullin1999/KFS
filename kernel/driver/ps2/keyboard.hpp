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

#ifndef __KERNEL_DRIVER_PS2_SERVICE_IMPL_KEYBOARD_HPP__
# define __KERNEL_DRIVER_PS2_SERVICE_IMPL_KEYBOARD_HPP__

# include <cstdint>
# include "driver/utils/port.hpp"
# include "driver/common_interface/keyboard.hpp"

namespace kfs::driver::ps2 {

class Keyboard : public kfs::driver::interface::IKeyboard {
public:
	Keyboard(Decoder &&decoder) :
		IKeyboard(std::move(decoder)),
		_port(0x60) { }

	uint8_t	read() const override;
private:
	kfs::driver::utils::PortByte	_port;
};

}

#endif // __KERNEL_DRIVER_PS2_SERVICE_IMPL_KEYBOARD_HPP__
