/**
 * @file command_press_scroll.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "command_press_scroll.hpp"

namespace kfs::driver::common {

void	CommandPressScroll::execute() {
	if (_text_display->get_current_column() == 0) {
		return ;
	}
	for (size_t y = 0; y < _text_display->get_column() - 1; ++y) {
		for (size_t x = 0; x < _text_display->get_row(); ++x) {
			_text_display->write(_text_display->read(x, y + 1), x, y);
		}
	}
	for (size_t y = _text_display->get_column() - 1; y < _text_display->get_column(); ++y) {
		for (size_t x = 0; x < _text_display->get_row(); ++x) {
			_text_display->write(' ', x, y);
		}
	}
	_text_display->set_cursor_position(_text_display->get_current_row(), _text_display->get_current_column() - 1);
}

}
