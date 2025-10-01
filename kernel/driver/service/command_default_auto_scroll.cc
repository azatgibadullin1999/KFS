/**
 * @file command_default_auto_scroll.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <cctype>

#include "command_press_scroll.hpp"
#include "command_default_auto_scroll.hpp"

namespace kfs::driver::common {

void	CommandDefaultAutoScroll::execute() {
	static auto&&	scroll = CommandPressScroll(0, mTextDisplay);
	if (!std::isprint(mChar))
			return;
	size_t	row = mTextDisplay->getCurrentRow();
	size_t	column = mTextDisplay->getCurrentColumn();
		
	mTextDisplay->write(mChar, row, column);
	if (++row == mTextDisplay->getRow()) {
		row = 0;
		if (++column == mTextDisplay->getColumn() - 1) {
			mTextDisplay->setCursorPosition(row, column);
			scroll.execute();
			row = mTextDisplay->getCurrentRow();
			column = mTextDisplay->getCurrentColumn();
		}
	}
	mTextDisplay->setCursorPosition(row, column);
}

}
