/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:02:21 by larlena           #+#    #+#             */
/*   Updated: 2024/03/13 20:19:04 by larlena          ###   ########.fr       */
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
	Keyboard(kfs::driver::interface::IKeyboardDecoder *decoder) :
		IKayboard(decoder),
		mPort(0x60),
		mKeysState() {
		ft_bzero(mKeysState, sizeof(mKeysState));
	}

	uint8_t	read() override;
private:
	kfs::driver::utils::Port	mPort;
	uint8_t	mKeysState[128];
};

}

#endif // __KERNEL_DRIVER_PS2_SERVICE_IMPL_KEYBOARD_HPP__