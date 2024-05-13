/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   port.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:47:08 by larlena           #+#    #+#             */
/*   Updated: 2024/05/13 15:42:52 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_UTILS_PORT_HPP__
# define __KFS_KERNEL_DRIVER_UTILS_PORT_HPP__

# include <stdint.h>

namespace kfs::driver::utils {

class PortBase{
public:
	PortBase(uint16_t port) : mPort(port) { }
protected:
	uint16_t	mPort;
};

class PortByte : public PortBase{
public:
	using PortBase::PortBase;
	void	write(uint8_t value) const;
	uint8_t read() const;
};

class PortWord : public PortBase{
public:
	using PortBase::PortBase;
	void	write(uint16_t value) const;
	uint16_t read() const;
};

}

#endif // __KFS_KERNEL_DRIVER_UTILS_PORT_HPP__
