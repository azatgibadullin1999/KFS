/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   port.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:47:08 by larlena           #+#    #+#             */
/*   Updated: 2024/03/23 14:02:01 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_UTILS_PORT_HPP__
# define __KFS_KERNEL_DRIVER_UTILS_PORT_HPP__

# include <stdint.h>

namespace kfs::driver::utils {

class Port {
public:
	Port(uint16_t port) : mPort(port) { }

	void	write(uint8_t value) const;
	uint8_t read() const;
private:
	uint16_t	mPort;
};

}

#endif // __KFS_KERNEL_DRIVER_UTILS_PORT_HPP__
