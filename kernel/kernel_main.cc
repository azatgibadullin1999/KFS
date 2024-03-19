/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel_main.cc                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:46:12 by larlena           #+#    #+#             */
/*   Updated: 2024/03/19 02:56:49 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "./utils/libft.h"
#include "./driver/ps2/service/impl/keyboard.hpp"
#include "./driver/vga/service/impl/textmode.hpp"
#include "./driver/utils/usqwerty.hpp"

#if defined(__linux__)
# error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#if !defined(__i386__)
# error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

const char	*header = "\
         :::         :::::::       :::::::::	            :::      ::::::::\n\
        :+:        :+:   :+:      :+:    :+:	          :+:      :+:    :+:\n\
       +:+         +:+ +:+       +:+    +:+	        +:+ +:+         +:+\n\
      +#+          +#++:  ++#   +#+    +:+	      +#+  +:+       +#+\n\
     +#+         +#+ +#+#+#    +#+    +#+	    +#+#+#+#+#+   +#+\n\
    #+#        #+#   #+#+     #+#    #+#	         #+#    #+#\n\
   ##########  ##########    #########	        	###   ########.fr\n\n"; 

extern "C" void kernel_main(void) {
	auto&&	display = kfs::driver::vga::VGATextMode();
	auto&&	codes = kfs::driver::common::USqwerty();
	auto&&	keyboard = kfs::driver::ps2::Keyboard(&codes);
	uint8_t	buff;

	display.write(header);
	keyboard.read();
	while (1) {
		buff = keyboard.read();
		if (buff == 0xFF) {
			continue;
		}
		display.write(buff);
	}
}