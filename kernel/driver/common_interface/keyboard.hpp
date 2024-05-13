/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:42:09 by larlena           #+#    #+#             */
/*   Updated: 2024/04/15 15:40:16 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DIRVER_COMMON_INTERFACE_KEYBOARD__
# define __KFS_KERNEL_DIRVER_COMMON_INTERFACE_KEYBOARD__

# include "utils/libft.hpp"

namespace kfs::driver::interface {

class IKeyboard {
public:
	IKeyboard() {
		kfs::bzero(mKeysState, sizeof(mKeysState));
	}

	virtual uint8_t	read() = 0;

	bool	isPressed(const uint8_t &code) const {
		return mKeysState[code];
	}
protected:
 	uint8_t	mKeysState[128];
};

}

#endif // __KFS_KERNEL_DIRVER_COMMON_INTERFACE_KEYBOARD__
