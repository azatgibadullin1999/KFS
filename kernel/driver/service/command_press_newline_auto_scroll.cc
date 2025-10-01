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
	static auto&&	scroll = CommandPressScroll(0, mTextDisplay);
	size_t	column = mTextDisplay->getCurrentColumn();
	size_t	row = 0;

	if (++column == mTextDisplay->getColumn() - 1) {
		mTextDisplay->setCursorPosition(row, column);
		scroll.execute();
		row = mTextDisplay->getCurrentRow();
		column = mTextDisplay->getCurrentColumn();
	}
	mTextDisplay->setCursorPosition(row, column);
}

}
