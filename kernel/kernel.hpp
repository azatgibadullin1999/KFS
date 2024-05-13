/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:00:57 by larlena           #+#    #+#             */
/*   Updated: 2024/05/26 22:00:27 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_KERNEL_HPP__
# define __KFS_KERNEL_KERNEL_HPP__

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include "utils/libft.hpp"
# include "driver/ps2/service/impl/keyboard.hpp"
# include "driver/vga/service/impl/text_display.hpp"
# include "driver/service/symbol_processor_auto_scroll.hpp"
# include "driver/service/usqwerty.hpp"
# include "console.hpp"
# include "service/shell/shell.hpp"

# include "service/memory/memory.hpp"

# include "../boot/multiboot.h"

class Kernel {
public:
	static Kernel	init(multiboot_info_t* mbd) {
		auto&&	memory [[maybe_unused]] = Memory::init(reinterpret_cast<multiboot_memory_map_t *>(mbd->mmap_addr), mbd->mmap_length);

		static auto&&	display = kfs::driver::vga::VGATextDisplay();
		static auto&&	keyboard = kfs::driver::ps2::Keyboard(kfs::driver::common::USqwerty());
		static auto&&	processor = kfs::driver::common::SymbolProcessorAutoScroll(&display);
		kfs::ConsoleSingleton::getInstance().setTextDisplay(&display);
		kfs::ConsoleSingleton::getInstance().setKeyboard(&keyboard);
		kfs::ConsoleSingleton::getInstance().setSymbolProcessor(&processor);
		
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
		auto&&	shell = kfs::Shell(&kfs::ConsoleSingleton::getInstance());

		kfs::ConsoleSingleton::getInstance().write(header);
		while (1) {
			shell.process();
		}

	}
};

#endif // __KFS_KERNEL_KERNEL_HPP__