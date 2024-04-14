/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kayboard.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:42:09 by larlena           #+#    #+#             */
/*   Updated: 2024/04/14 11:05:28 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DIRVER_COMMON_INTERFACE_KAYBOARD__
# define __KFS_KERNEL_DIRVER_COMMON_INTERFACE_KAYBOARD__

# include "utils/libft.h"

namespace kfs::driver::interface {

class IKayboard {
public:
	IKayboard() {
		ft_bzero(mKaysState, sizeof(mKaysState));
	}

	virtual uint8_t	read() = 0;

	bool	isPressed(const uint8_t &code) const {
		return mKaysState[code];
	}
protected:
 	uint8_t	mKaysState[128];
};

}

#endif // __KFS_KERNEL_DIRVER_COMMON_INTERFACE_KAYBOARD__
