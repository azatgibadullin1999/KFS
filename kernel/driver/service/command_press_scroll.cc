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
	if (mTextDisplay->getCurrentColumn() == 0)
		return ;
	for (size_t y = 0; y < mTextDisplay->getColumn() - 1; ++y) {
		for (size_t x = 0; x < mTextDisplay->getRow(); ++x) {
			mTextDisplay->write(mTextDisplay->read(x, y + 1), x, y);
		}
	}
	for (size_t y = mTextDisplay->getColumn() - 1; y < mTextDisplay->getColumn(); ++y) {
		for (size_t x = 0; x < mTextDisplay->getRow(); ++x) {
			mTextDisplay->write(' ', x, y);
		}
	}
	mTextDisplay->setCursorPosition(mTextDisplay->getCurrentRow(), mTextDisplay->getCurrentColumn() - 1);
}

}
