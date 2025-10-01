/**
 * @file symbol_processor_default.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_SYMBOL_PROCESSOR_DEFAULT_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_SYMBOL_PROCESSOR_DEFAULT_HPP__

# include "driver/common_interface/symbol_processor.hpp"
# include "driver/common_interface/keyboard.hpp"
# include "driver/common_interface/text_display.hpp"
# include "command_press_backspace.hpp"
# include "command_press_newline.hpp"
# include "command_press_scroll.hpp"
# include "command_press_tab.hpp"
# include "command_default.hpp"

namespace kfs::driver::common {

class SymbolProcessorDefault final : public kfs::driver::interface::SymbolProcessor <
	kfs::driver::common::CommandPressBackspace,
	kfs::driver::common::CommandPressNewLine,
	kfs::driver::common::CommandPressScroll,
	kfs::driver::common::CommandPressTab,
	kfs::driver::common::CommandDefault
> {
public:
	SymbolProcessorDefault(kfs::driver::interface::ITextDisplay *textDisplay) :
	SymbolProcessor(
		CommandPressBackspace('\b' ,textDisplay),
		CommandPressNewLine('\n', textDisplay),
		CommandPressScroll(kfs::driver::interface::IKeyboard::Decoder::DOWN, textDisplay),
		CommandPressTab('\t', textDisplay, 8),
		CommandDefault(0, textDisplay)
		) { }
};

}

#endif // __KFS_KERNEL_DRIVER_SERVICE_SYMBOL_PROCESSOR_DEFAULT_HPP__