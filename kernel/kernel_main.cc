/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel_main.cc                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:46:12 by larlena           #+#    #+#             */
/*   Updated: 2024/03/25 17:23:30 by larlena          ###   ########.fr       */
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
	auto&&	keyboard = kfs::driver::ps2::Keyboard();
	char	strbuff[8];
	uint8_t	buff;

	// display.write(header);
	// display[2]->operator[](3)->operator=('2');
	display.column(2)->row(1)->put('2');
	keyboard.read();
	while (1) {
		buff = keyboard.read();
		if (buff == 0xFF) {
			continue;
		}
		// keyboard.isPressed(codes.scanBackward(buff));
		// display.write(ft_itoa(buff, strbuff, 16));
		// display.write('\n');
		display.write((buff = codes.scanLowercase(buff)));
		// display.write('\n');
		// display.write(ft_itoa(codes.scanBackward(buff), strbuff, 16));
		// display.write('\n');
		// display.write('\n');
	}
}