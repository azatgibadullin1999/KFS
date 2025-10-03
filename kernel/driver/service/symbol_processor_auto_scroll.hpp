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

#ifndef KFS_KERNEL_DRIVER_SERVICE_SPECIAL_SYMBOL_PROCESSOR_AUTO_SCROLL_HPP
# define KFS_KERNEL_DRIVER_SERVICE_SPECIAL_SYMBOL_PROCESSOR_AUTO_SCROLL_HPP

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
	SymbolProcessorAutoScroll(kfs::driver::interface::ITextDisplay *text_display) :
	SymbolProcessor(
		CommandPressTab('\t', text_display, 8),
		CommandPressScroll(kfs::driver::interface::IKeyboard::Decoder::DOWN, text_display),
		CommandPressBackspace('\b', text_display),
		CommandDefaultAutoScroll(0, text_display),
		CommandPressNewLineAutoScroll('\n', text_display)
		) { }
};

}

#endif // KFS_KERNEL_DRIVER_SERVICE_SPECIAL_SYMBOL_PROCESSOR_AUTO_SCROLL_HPP
