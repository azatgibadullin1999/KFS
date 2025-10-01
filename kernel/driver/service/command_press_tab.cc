/**
 * @file command_press_tab.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "command_press_tab.hpp"

namespace kfs::driver::common {

void	CommandPressTab::execute() {
	auto&&	currentRow = mTextDisplay->getCurrentRow();
	auto&&	newCursorPositionByRow = currentRow + (mTabSize - (currentRow % mTabSize));

	mTextDisplay->setCursorPosition(newCursorPositionByRow, mTextDisplay->getCurrentColumn());
}

}
