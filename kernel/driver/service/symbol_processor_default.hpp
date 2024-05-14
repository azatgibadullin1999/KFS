/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_processor_default.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:27:22 by larlena           #+#    #+#             */
/*   Updated: 2024/05/17 19:31:50 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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