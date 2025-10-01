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
	size_t	row = mTextDisplay->getCurrentRow();
	size_t	column = mTextDisplay->getCurrentColumn();

	if (row == 0 && column != 0) {
		column -= 1;
		row = mTextDisplay->getRow();
	}
	row -= 1;
	mTextDisplay->write(' ', row, column);
	mTextDisplay->setCursorPosition(row, column);	
}

}