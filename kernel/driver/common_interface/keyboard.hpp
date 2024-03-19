/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:42:09 by larlena           #+#    #+#             */
/*   Updated: 2024/03/15 17:20:36 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DIRVER_COMMON_INTERFACE_KEYBOARD__
# define __KFS_KERNEL_DIRVER_COMMON_INTERFACE_KEYBOARD__

# include "keyboard_decoder.hpp"

namespace kfs::driver::interface {

class IKayboard {
public:
	IKayboard(IKeyboardDecoder *decoder) : mDecoder(decoder) { }

	virtual uint8_t	read() = 0;
protected:
	IKeyboardDecoder	*mDecoder;
};

}

#endif // __KFS_KERNEL_DIRVER_COMMON_INTERFACE_KEYBOARD__