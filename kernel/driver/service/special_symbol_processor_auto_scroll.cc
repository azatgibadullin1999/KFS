/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_symbol_processor_auto_scroll.cc            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:32:43 by larlena           #+#    #+#             */
/*   Updated: 2024/05/12 17:33:18 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "driver/common_interface/keyboard_decoder.hpp"
#include "special_symbol_processor_auto_scroll.hpp"
#include "command_default_auto_scroll.hpp"
#include "command_press_newline_auto_scroll.hpp"
#include "command_press_backspace.hpp"
#include "command_press_scroll.hpp"
#include "command_press_tab.hpp"

namespace kfs::driver::common {

kfs::interface::ICommand	*SpecialSymbolProcessorAutoScroll::process(const char &symbol) {
	static CommandPressBackspace		backspace(mTextmode);
	static CommandPressNewLineAutoScroll	newLine(mTextmode);
	static CommandPressScroll		scroll(mTextmode);
	static CommandPressTab			tab(mTextmode, 8);
	static CommandDefaultAutoScroll		conventional(mTextmode);


	if (symbol == '\b') {
		return &backspace;
	} else if (symbol == '\n') {
		return &newLine;
	} else if (symbol == '\t') {
		return &tab;
	} else if (static_cast<uint8_t>(symbol) == kfs::driver::interface::IKeyboardDecoder::DOWN) {
		return &scroll;
	}
	conventional = symbol;
	return &conventional;
}

}
