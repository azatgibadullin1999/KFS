/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   port.cc                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:47:10 by larlena           #+#    #+#             */
/*   Updated: 2024/05/13 15:42:52 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "port.hpp"

namespace kfs::driver::utils {

uint8_t PortByte::read() const {
	uint8_t	retValue;
	asm volatile (
	"inb %1, %0\n\t"
		: "=a" (retValue)
		: "Nd" (this->mPort));
	return retValue;
}

void	PortByte::write(uint8_t value) const {
	asm volatile (
	"outb %0, %1\n\t"
		:
		: "a" (value), "Nd" (this->mPort));
}

uint16_t	PortWord::read() const {
	uint16_t	retValue;
	asm volatile (
	"inw %1, %0\n\t"
		: "=a" (retValue)
		: "Nd" (this->mPort));
	return retValue;
}

void	PortWord::write(uint16_t value) const {
	asm volatile (
	"outw %0, %1\n\t"
		:
		: "a" (value), "Nd" (this->mPort));
}

}
