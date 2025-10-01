/**
 * @file symbol_processor_auto_scroll.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_SPECIAL_SYMBOL_PROCESSOR_AUTO_SCROLL_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_SPECIAL_SYMBOL_PROCESSOR_AUTO_SCROLL_HPP__

# include "driver/common_interface/symbol_processor.hpp"
# include "driver/common_interface/keyboard.hpp"
# include "command_press_newline_auto_scroll.hpp"
# include "command_default_auto_scroll.hpp"
# include "command_press_backspace.hpp"
# include "command_press_scroll.hpp"
# include "command_press_tab.hpp"

namespace kfs::driver::common {

class SymbolProcessorAutoScroll final : public kfs::driver::interface::SymbolProcessor <
	kfs::driver::common::CommandPressTab,
	kfs::driver::common::CommandPressScroll,
	kfs::driver::common::CommandPressBackspace,
	kfs::driver::common::CommandDefaultAutoScroll,
	kfs::driver::common::CommandPressNewLineAutoScroll
> {
public:
	SymbolProcessorAutoScroll(kfs::driver::interface::ITextDisplay *textDisplay) :
	SymbolProcessor(
		CommandPressTab('\t', textDisplay, 8),
		CommandPressScroll(kfs::driver::interface::IKeyboard::Decoder::DOWN, textDisplay),
		CommandPressBackspace('\b', textDisplay),
		CommandDefaultAutoScroll(0, textDisplay),
		CommandPressNewLineAutoScroll('\n', textDisplay)
		) { }
};

}

#endif // __KFS_KERNEL_DRIVER_SERVICE_SPECIAL_SYMBOL_PROCESSOR_AUTO_SCROLL_HPP__
