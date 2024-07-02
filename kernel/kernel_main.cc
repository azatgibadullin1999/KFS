/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel_main.cc                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:46:12 by larlena           #+#    #+#             */
/*   Updated: 2024/05/22 15:37:09 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include "kernel.hpp"
#include "utils/libft.hpp"
#include "driver/ps2/service/impl/keyboard.hpp"
#include "driver/vga/service/impl/text_display.hpp"
#include "driver/service/symbol_processor_auto_scroll.hpp"
#include "driver/service/usqwerty.hpp"
#include "console.hpp"
#include "service/shell/shell.hpp"

#include "arch/x86/gdt_default.hpp"

#if defined(__linux__)
# error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

#if !defined(__i386__)
# error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

void	*stack_top;

const char	*header = "\
         :::         :::::::       :::::::::	            :::      ::::::::\n\
        :+:        :+:   :+:      :+:    :+:	          :+:      :+:    :+:\n\
       +:+         +:+ +:+       +:+    +:+	        +:+ +:+         +:+\n\
      +#+          +#++:  ++#   +#+    +:+	      +#+  +:+       +#+\n\
     +#+         +#+ +#+#+#    +#+    +#+	    +#+#+#+#+#+   +#+\n\
    #+#        #+#   #+#+     #+#    #+#	         #+#    #+#\n\
   ##########  ##########    #########	        	###   ########.fr\n\n";

extern "C" void kernel_main(void *stack_top_top) {
	stack_top = stack_top_top;
	auto&&	table [[maybe_unused]] = kfs::x86::GDTDefault();
	auto&&	display = kfs::driver::vga::VGATextDisplay();
	auto&&	keyboard = kfs::driver::ps2::Keyboard(kfs::driver::common::USqwerty());
	auto&&	processor = kfs::driver::common::SymbolProcessorAutoScroll(&display);
	auto&&	shell = kfs::Shell(&kfs::ConsoleSingleton::getInstance());
	kfs::ConsoleSingleton::getInstance().setTextDisplay(&display);
	kfs::ConsoleSingleton::getInstance().setKeyboard(&keyboard);
	kfs::ConsoleSingleton::getInstance().setSymbolProcessor(&processor);


	kfs::ConsoleSingleton::getInstance().write(header);
	while (1) {
		shell.process();
	}
}