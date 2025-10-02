/**
 * @file command_press_newline.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "command_press_newline.hpp"

namespace kfs::driver::common {

void	CommandPressNewLine::execute() {
	size_t	column = _text_display->get_current_column();
	size_t	row = 0;

	if (++column == _text_display->get_column()) {
		column = 0;
		_text_display->clear();
	}
	_text_display->set_cursor_position(row, column);
}

}