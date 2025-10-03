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

#ifndef KFS_KERNEL_DRIVER_SERVICE_SYMBOL_PROCESSOR_DEFAULT_HPP
# define KFS_KERNEL_DRIVER_SERVICE_SYMBOL_PROCESSOR_DEFAULT_HPP

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
	SymbolProcessorDefault(kfs::driver::interface::ITextDisplay *text_display) :
	SymbolProcessor(
		CommandPressBackspace('\b' ,text_display),
		CommandPressNewLine('\n', text_display),
		CommandPressScroll(kfs::driver::interface::IKeyboard::Decoder::DOWN, text_display),
		CommandPressTab('\t', text_display, 8),
		CommandDefault(0, text_display)
		) { }
};

}

#endif // KFS_KERNEL_DRIVER_SERVICE_SYMBOL_PROCESSOR_DEFAULT_HPP