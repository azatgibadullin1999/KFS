/**
 * @file command_press_newline_auto_scroll.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "command_press_newline_auto_scroll.hpp"
#include "command_press_scroll.hpp"

namespace kfs::driver::common {

void	CommandPressNewLineAutoScroll::execute() {
	static auto&&	scroll = CommandPressScroll(0, _text_display);
	size_t	column = _text_display->get_current_column();
	size_t	row = 0;

	if (++column == _text_display->get_column() - 1) {
		_text_display->set_cursor_position(row, column);
		scroll.execute();
		row = _text_display->get_current_row();
		column = _text_display->get_current_column();
	}
	_text_display->set_cursor_position(row, column);
}

}
