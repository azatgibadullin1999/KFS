/**
 * @file port.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

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
