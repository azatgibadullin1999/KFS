/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:42:09 by larlena           #+#    #+#             */
/*   Updated: 2024/03/23 14:01:24 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DIRVER_COMMON_INTERFACE_KEYBOARD__
# define __KFS_KERNEL_DIRVER_COMMON_INTERFACE_KEYBOARD__

# include "keyboard_decoder.hpp"

namespace kfs::driver::interface {

class IKayboard {
public:
	IKayboard() { }

	virtual uint8_t	read() = 0;
	virtual bool	isPressed(const uint8_t &code) const = 0;
};

}

#endif // __KFS_KERNEL_DIRVER_COMMON_INTERFACE_KEYBOARD__
