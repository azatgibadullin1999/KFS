/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_symbol_processor.cc                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 01:29:56 by larlena           #+#    #+#             */
/*   Updated: 2024/04/15 11:06:39 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "driver/common_interface/keyboard_decoder.hpp"
#include "special_symbol_processor.hpp"
#include "command_press_backspace.hpp"
#include "command_press_newline.hpp"
#include "command_press_scroll.hpp"
#include "command_press_tab.hpp"
#include "command_default.hpp"

namespace kfs::driver::common {

kfs::interface::ICommand	*SpecialSymbolProcessor::process(const char &symbol) const {
	static CommandPressBackspace	backspace(mTextmode);
	static CommandPressNewLine	newLine(mTextmode);
	static CommandPressScroll	scroll(mTextmode);
	static CommandPressTab		tab(mTextmode, 8);
	static CommandDefault		conventional(mTextmode);

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
