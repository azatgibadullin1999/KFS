/**
 * @file command_press_backspace.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "command_press_backspace.hpp"

namespace kfs::driver::common {

void	CommandPressBackspace::execute() {
	size_t	row = _text_display->get_current_row();
	size_t	column = _text_display->get_current_column();

	if (row == 0 && column != 0) {
		column -= 1;
		row = _text_display->get_row();
	}
	row -= 1;
	_text_display->write(' ', row, column);
	_text_display->set_cursor_position(row, column);	
}

}