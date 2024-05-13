/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   port.cc                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:47:10 by larlena           #+#    #+#             */
/*   Updated: 2024/03/19 15:34:25 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "port.hpp"

namespace kfs::driver::utils {

uint8_t Port::read() const {
	uint8_t	retValue;
	asm volatile (
	"inb %1, %0\n\t"
		: "=a" (retValue)
		: "Nd" (this->mPort));
	return retValue;
}

void	Port::write(uint8_t value) const {
	asm volatile (
	"outb %0, %1\n\t"
		:
		: "a" (value), "Nd" (this->mPort));
}

}
