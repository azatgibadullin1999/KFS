/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usqwerty.cc                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:16:16 by larlena           #+#    #+#             */
/*   Updated: 2024/04/14 19:06:23 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "usqwerty.hpp"
#include "utils/libft.h"

namespace kfs::driver::common {

USqwerty::USqwerty(kfs::driver::interface::IKayboard *keyboard) :
IKayboardDecoder(keyboard) {
	for (uint8_t it = 0; it < sizeof(mLowercase); ++it) {
		mBackward[mLowercase[it]] = it;
	}
	for (uint8_t it = 0; it < sizeof(mUppercase); ++it) {
		mBackward[mUppercase[it]] = it;
	}
}

uint8_t USqwerty::scan(const uint8_t &code) const {
	static bool	capsLock = 0;

	if (mLowercase[code] == CAPS)
		capsLock = !capsLock;		
	if (capsLock)
		return  ft_toupper(mLowercase[code]);
	return mLowercase[code];
}

}
