/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputdevice.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 11:51:27 by larlena           #+#    #+#             */
/*   Updated: 2024/03/23 14:01:42 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KERNEL_DRIVER_COMMON_INTERFACES_INPUTDEVICE_HPP__
# define __KERNEL_DRIVER_COMMON_INTERFACES_INPUTDEVICE_HPP__

# include <stdint.h>

namespace kfs::driver::interface {

class IInputDevice {
public:
	virtual ~IInputDevice();
	virtual uint16_t	read() = 0;
};

}

#endif // __KERNEL_DRIVER_COMMON_INTERFACES_INPUTDEVICE_HPP__
