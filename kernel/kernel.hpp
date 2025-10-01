/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:00:57 by larlena           #+#    #+#             */
/*   Updated: 2025/09/27 18:41:00 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_KERNEL_HPP__
# define __KFS_KERNEL_KERNEL_HPP__

# include <stdbool.h>
# include <stddef.h>
# include "driver/ps2/keyboard.hpp"
# include "driver/vga/text_display.hpp"
# include "driver/service/symbol_processor_auto_scroll.hpp"
# include "driver/service/usqwerty.hpp"
# include "service/console/console.hpp"
# include "service/shell/shell.hpp"
# include "service/panic/panic.hpp"
# include "service/memory/memory.hpp"
# include "../boot/multiboot.h"

namespace kfs {

class Kernel {
public:
	static Kernel	init(multiboot_info_t* mbd) {
		static auto&&	panic = PanicHandler{};
		static auto&&	display = driver::vga::VGATextDisplay();
		static auto&&	keyboard = driver::ps2::Keyboard(driver::common::USqwerty());
		static auto&&	processor = driver::common::SymbolProcessorAutoScroll(&display);
		console::instance().setTextDisplay(&display);
		console::instance().setKeyboard(&keyboard);
		console::instance().setSymbolProcessor(&processor);

		auto&&	memory [[maybe_unused]] = Memory::init(
			reinterpret_cast<multiboot_memory_map_t *>(mbd->mmap_addr),
			mbd->mmap_length,
			&mbd->u.elf_sec);
		
		static auto&&	kernel = Kernel();
		return kernel;
	}

	void	start() {
		const static char	*header = "\
         :::         :::::::       :::::::::	            :::      ::::::::\n\
        :+:        :+:   :+:      :+:    :+:	          :+:      :+:    :+:\n\
       +:+         +:+ +:+       +:+    +:+	        +:+ +:+         +:+\n\
      +#+          +#++:  ++#   +#+    +:+	      +#+  +:+       +#+\n\
     +#+         +#+ +#+#+#    +#+    +#+	    +#+#+#+#+#+   +#+\n\
    #+#        #+#   #+#+     #+#    #+#	         #+#    #+#\n\
   ##########  ##########    #########	        	###   ########.fr\n\n";
		auto&&	shell = Shell(&console::instance());

		console::instance().write(header);
		while (1) {
			shell.process();
		}
	}
};

} // namespace kfs

#endif // __KFS_KERNEL_KERNEL_HPP__