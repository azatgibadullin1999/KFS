/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel_main.cc                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:46:12 by larlena           #+#    #+#             */
/*   Updated: 2024/04/17 16:58:15 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "utils/libft.hpp"
#include "driver/ps2/service/impl/keyboard.hpp"
#include "driver/vga/service/impl/textmode.hpp"
#include "driver/service/special_symbol_processor.hpp"
#include "driver/service/usqwerty.hpp"
#include "console.hpp"

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
	auto&&	keyboard = kfs::driver::ps2::Keyboard();
	auto&&	codes = kfs::driver::common::USqwerty(&keyboard);
	auto&&	processor = kfs::driver::common::SpecialSymbolProcessor(&display);
	kfs::ConsoleSingleton::getInstance().setTextmode(&display);
	kfs::ConsoleSingleton::getInstance().setKeyboard(&keyboard);
	kfs::ConsoleSingleton::getInstance().setKeyboardDecoder(&codes);
	kfs::ConsoleSingleton::getInstance().setSpecialSymbolProcessor(&processor);

	kfs::ConsoleSingleton::getInstance().write(header);
	while (1) {
		kfs::ConsoleSingleton::getInstance().process();
	}
}