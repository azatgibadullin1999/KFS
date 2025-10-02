/**
 * @file port.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "port.hpp"

namespace kfs::driver::utils {

uint8_t PortByte::read() const {
	uint8_t	ret;
	asm volatile (
	"inb %1, %0\n\t"
		: "=a" (ret)
		: "Nd" (this->_port));
	return ret;
}

void	PortByte::write(uint8_t value) const {
	asm volatile (
	"outb %0, %1\n\t"
		:
		: "a" (value), "Nd" (this->_port));
}

uint16_t	PortWord::read() const {
	uint16_t	ret;
	asm volatile (
	"inw %1, %0\n\t"
		: "=a" (ret)
		: "Nd" (this->_port));
	return ret;
}

void	PortWord::write(uint16_t value) const {
	asm volatile (
	"outw %0, %1\n\t"
		:
		: "a" (value), "Nd" (this->_port));
}

}
