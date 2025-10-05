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

# include <kfs/symbol_processor.hpp>
# include <kfs/keyboard.hpp>
# include <kfs/text_display.hpp>

# include "command_press_backspace.hpp"
# include "command_press_newline.hpp"
# include "command_press_scroll.hpp"
# include "command_press_tab.hpp"
# include "command_default.hpp"

namespace kfs::driver::common {

class SymbolProcessorDefault final : public kfs::driver::SymbolProcessor <
	kfs::driver::common::CommandPressBackspace,
	kfs::driver::common::CommandPressNewLine,
	kfs::driver::common::CommandPressScroll,
	kfs::driver::common::CommandPressTab,
	kfs::driver::common::CommandDefault
> {
public:
	SymbolProcessorDefault(kfs::ITextDisplay *text_display) :
	SymbolProcessor(
		CommandPressBackspace('\b' ,text_display),
		CommandPressNewLine('\n', text_display),
		CommandPressScroll(kfs::driver::IKeyboard::Decoder::DOWN, text_display),
		CommandPressTab('\t', text_display, 8),
		CommandDefault(0, text_display)
		) { }
};

}

#endif // KFS_KERNEL_DRIVER_SERVICE_SYMBOL_PROCESSOR_DEFAULT_HPP