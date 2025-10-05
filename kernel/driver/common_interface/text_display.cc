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

#include <kfs/text_display.hpp>

namespace kfs {

bool	ITextDisplay::set_cursor_position(size_t row, size_t column) {
	if (column < _columns_number && row < _rows_number) {
		_column = column;
		_row = row;
		return false;
	}
	return true;
}

}
