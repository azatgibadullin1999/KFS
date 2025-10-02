/**
 * @file kernel.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_KERNEL_HPP__
# define __KFS_KERNEL_KERNEL_HPP__

# include <cstddef>
# include <cstdbool>

# include <multiboot.h>

# include "service/shell/shell.hpp"
# include "service/panic/panic.hpp"
# include "service/memory/memory.hpp"
# include "service/console/console.hpp"

# include "driver/ps2/keyboard.hpp"
# include "driver/vga/text_display.hpp"
# include "driver/service/usqwerty.hpp"
# include "driver/service/symbol_processor_auto_scroll.hpp"

extern "C" {
	extern std::byte _kfs_sections_begin;
	extern std::byte _text_begin;
	extern std::byte _text_end;
	extern std::byte _rodata_begin;
	extern std::byte _rodata_end;
	extern std::byte _data_begin;
	extern std::byte _data_end;
	extern std::byte _bss_begin;
	extern std::byte _bss_end;
	extern std::byte _kfs_sections_end;
}

namespace kfs {

class Kernel {
public:
	static Kernel	init(multiboot_info_t* mbd) {
		PanicHandler{};
		static auto&&	display = driver::vga::VGATextDisplay();
		static auto&&	keyboard = driver::ps2::Keyboard(driver::common::USqwerty());
		static auto&&	processor = driver::common::SymbolProcessorAutoScroll(&display);
		console::instance().set_text_display(&display);
		console::instance().set_keyboard(&keyboard);
		console::instance().set_symbol_processor(&processor);

		auto&&	memory [[maybe_unused]] = Memory::init(
			reinterpret_cast<multiboot_memory_map_t *>(mbd->mmap_addr),
			mbd->mmap_length);
		
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