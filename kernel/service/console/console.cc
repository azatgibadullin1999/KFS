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
	mScanCodeBuff = _keyboard->read();
	if (mScanCodeBuff == 0xFF) {
		return;
	}
	_processor->process(mCharBuff);
	_text_display->updateCursorPosition();
}

void	kfs::Console::write(char c) {
	_processor->process(c);
	_text_display->updateCursorPosition();
}

void	kfs::Console::write(const char *str) {
	for (size_t it = 0; str[it]; ++it) {
		_processor->process(str[it]);
	}
	_text_display->updateCursorPosition();
}

char	kfs::Console::read() {
	mScanCodeBuff = _keyboard->read();
	if (mScanCodeBuff == 0xFF) {
		return -1;
	}
	return mScanCodeBuff;
}

char	kfs::Console::readBlocking() {
	char	buff = -1;

	while (buff == -1) {
		buff = read();
	}

	return buff;
}
