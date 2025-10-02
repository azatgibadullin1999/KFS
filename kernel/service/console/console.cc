/**
 * @file console.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "console.hpp"

void	kfs::Console::process() {
	_scan_code_buff = _keyboard->read();
	if (_scan_code_buff == 0xFF) {
		return;
	}
	_processor->process(_char_buff);
	_text_display->update_cursor_position();
}

void	kfs::Console::write(char c) {
	_processor->process(c);
	_text_display->update_cursor_position();
}

void	kfs::Console::write(const char *str) {
	for (size_t it = 0; str[it]; ++it) {
		_processor->process(str[it]);
	}
	_text_display->update_cursor_position();
}

char	kfs::Console::read() {
	_scan_code_buff = _keyboard->read();
	if (_scan_code_buff == 0xFF) {
		return -1;
	}
	return _scan_code_buff;
}

char	kfs::Console::read_blocking() {
	char	buff = -1;

	while (buff == -1) {
		buff = read();
	}

	return buff;
}
