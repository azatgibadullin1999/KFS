/**
 * @file text_display.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "text_display.hpp"

namespace kfs::driver::interface {

bool	ITextDisplay::setCursorPosition(size_t row, size_t column) {
	if (column < mColumnsNumber && row < mRowsNumber) {
		mColumn = column;
		mRow = row;
		return false;
	}
	return true;
}

}
