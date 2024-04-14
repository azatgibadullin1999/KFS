/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kayboard.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:02:21 by larlena           #+#    #+#             */
/*   Updated: 2024/04/14 11:05:07 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KERNEL_DRIVER_PS2_SERVICE_IMPL_KAYBOARD_HPP__
# define __KERNEL_DRIVER_PS2_SERVICE_IMPL_KAYBOARD_HPP__

# include <stdint.h>
# include "driver/utils/port.hpp"
# include "driver/common_interface/kayboard.hpp"

namespace kfs::driver::ps2 {

class Kayboard : public kfs::driver::interface::IKayboard {
public:
	Kayboard() :
		IKayboard(),
		mPort(0x60) { }

	uint8_t	read() override;
private:
	kfs::driver::utils::Port	mPort;
};

}

#endif // __KERNEL_DRIVER_PS2_SERVICE_IMPL_KAYBOARD_HPP__
