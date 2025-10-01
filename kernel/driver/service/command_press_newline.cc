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
	size_t	column = mTextDisplay->getCurrentColumn();
	size_t	row = 0;

	if (++column == mTextDisplay->getColumn()) {
		column = 0;
		mTextDisplay->clear();
	}
	mTextDisplay->setCursorPosition(row, column);
}

}