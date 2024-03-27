/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel_main.cc                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:46:12 by larlena           #+#    #+#             */
/*   Updated: 2024/03/27 16:01:12 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "./utils/libft.h"
#include "./driver/ps2/service/impl/keyboard.hpp"
#include "./driver/vga/service/impl/textmode.hpp"
#include "./driver/utils/specialsymbolprocessor.hpp"
#include "./driver/utils/usqwerty.hpp"
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
	auto&&	codes = kfs::driver::common::USqwerty();
	auto&&	keyboard = kfs::driver::ps2::Keyboard();
	auto&&	processor = kfs::driver::common::SpecialSymbolProcessor(&display);

	auto&&	console = kfs::Console(&display, &processor, &codes, &keyboard);
	while (1) {
		console.doWork();
	}
}