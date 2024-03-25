/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:02:21 by larlena           #+#    #+#             */
/*   Updated: 2024/03/23 14:01:50 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KERNEL_DRIVER_PS2_SERVICE_IMPL_KEYBOARD_HPP__
# define __KERNEL_DRIVER_PS2_SERVICE_IMPL_KEYBOARD_HPP__

# include <stdint.h>
# include "../../../utils/port.hpp"
# include "../../../common_interface/keyboard.hpp"
# include "../../../../utils/libft.h"

namespace kfs::driver::ps2 {

class Keyboard : public kfs::driver::interface::IKayboard {
public:
	Keyboard() :
		mPort(0x60),
		mKeysState() {
		ft_bzero(mKeysState, sizeof(mKeysState));
	}

	uint8_t	read() override;
	bool	isPressed(const uint8_t &code) const override;
private:
	kfs::driver::utils::Port	mPort;
	uint8_t	mKeysState[128];
};

}

#endif // __KERNEL_DRIVER_PS2_SERVICE_IMPL_KEYBOARD_HPP__
