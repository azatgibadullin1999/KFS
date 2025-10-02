/**
 * @file command_default_auto_scroll.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <cctype>

#include "command_press_scroll.hpp"
#include "command_default_auto_scroll.hpp"

namespace kfs::driver::common {

void	CommandDefaultAutoScroll::execute() {
	static auto&&	scroll = CommandPressScroll(0, _text_display);
	if (!std::isprint(_character)) {
		return;
	}
	size_t	row = _text_display->get_current_row();
	size_t	column = _text_display->get_current_column();
		
	_text_display->write(_character, row, column);
	if (++row == _text_display->get_row()) {
		row = 0;
		if (++column == _text_display->get_column() - 1) {
			_text_display->set_cursor_position(row, column);
			scroll.execute();
			row = _text_display->get_current_row();
			column = _text_display->get_current_column();
		}
	}
	_text_display->set_cursor_position(row, column);
}

}
