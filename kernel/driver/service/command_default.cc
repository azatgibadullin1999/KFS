/**
 * @file command_default.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <cctype>

#include "command_default.hpp"

namespace kfs::driver::common {

void	CommandDefault::execute() {
	if (!std::isprint(_character)) {
		return;
	}
	size_t	row = _text_display->get_current_row();
	size_t	column = _text_display->get_current_column();
		
	_text_display->write(_character, row, column);
	if (++row == _text_display->get_row()) {
		row = 0;
		if (++column == _text_display->get_column()) {
			column = 0;
			_text_display->clear();
		}
	}
	_text_display->set_cursor_position(row, column);
}

bool	operator == (const CommandDefault &lhs [[maybe_unused]], const char &rhs) {
	return std::isprint(rhs);
}

bool	operator == (const char &lhs, const CommandDefault &rhs) {
	return rhs == lhs;
}

}