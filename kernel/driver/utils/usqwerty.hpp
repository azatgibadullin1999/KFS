/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usqwerty.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:35:10 by larlena           #+#    #+#             */
/*   Updated: 2024/03/27 17:18:16 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_UTILS_USQWERTY_HPP__
# define __KFS_KERNEL_DRIVER_UTILS_USQWERTY_HPP__

# include "../common_interface/keyboard_decoder.hpp"

namespace kfs::driver::common {

class USqwerty : public kfs::driver::interface::IKeyboardDecoder {
public:
	USqwerty(kfs::driver::interface::IKayboard *keyboard);

	uint8_t scan(const uint8_t &code) const override;

private:

	uint8_t	scanBackward(const uint8_t &code) const {
		return mBackward[code];
	}

	const uint8_t mLowercase[128] = {
	UNKNOWN,ESC,'1','2','3','4','5','6','7','8', '9','0','-','=','\b','\t',
	'q','w','e','r','t','y','u','i','o','p','[',']','\n',CTRL,'a','s',
	'd','f','g','h','j','k','l',';','\'','`',LSHFT,'\\','z','x','c','v','b','n','m',',',
	'.','/',RSHFT,'*',ALT,' ',CAPS,F1,F2,F3,F4,F5,F6,F7,F8,F9,F10,NUMLCK,SCRLCK,HOME,UP,PGUP,'-',LEFT,UNKNOWN,RIGHT,
	'+',END,DOWN,PGDOWN,INS,DEL,UNKNOWN,UNKNOWN,UNKNOWN,F11,F12,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,
	UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,
	UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,
	UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN
	};

	const uint8_t mUppercase[128] = {
	UNKNOWN,ESC,'!','@','#','$','%','^','&','*','(',')','_','+','\b','\t','Q','W','E','R',
	'T','Y','U','I','O','P','{','}','\n',CTRL,'A','S','D','F','G','H','J','K','L',':','"','~',LSHFT,'|','Z','X','C',
	'V','B','N','M','<','>','?',RSHFT,'*',ALT,' ',CAPS,F1,F2,F3,F4,F5,F6,F7,F8,F9,F10,NUMLCK,SCRLCK,HOME,UP,PGUP,'-',
	LEFT,UNKNOWN,RIGHT,'+',END,DOWN,PGDOWN,INS,DEL,UNKNOWN,UNKNOWN,UNKNOWN,F11,F12,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,
	UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,
	UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,
	UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN
	};

	uint8_t mBackward[256];

};

}

#endif // __KFS_KERNEL_DRIVER_UTILS_USQWERTY_HPP__
