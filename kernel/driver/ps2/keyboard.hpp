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

#ifndef KFS_KERNEL_DRIVER_PS2_SERVICE_IMPL_KEYBOARD_HPP
# define KFS_KERNEL_DRIVER_PS2_SERVICE_IMPL_KEYBOARD_HPP

# include <cstdint>
# include "../utils/port.hpp"
# include <kfs/keyboard.hpp>

namespace kfs::driver::ps2 {

class Keyboard : public kfs::IKeyboard {
public:
	Keyboard(Decoder &&decoder) :
		IKeyboard(std::move(decoder)),
		_port(0x60) { }

	uint8_t	read() const override;
private:
	kfs::driver::utils::PortByte	_port;
};

}

#endif // KFS_KERNEL_DRIVER_PS2_SERVICE_IMPL_KEYBOARD_HPP
