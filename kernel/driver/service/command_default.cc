/**
 * @file command_default.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <cctype>

#include "command_default.hpp"

namespace kfs::driver::common {

void	CommandDefault::execute() {
	if (!std::isprint(mChar))
			return;
	size_t	row = mTextDisplay->getCurrentRow();
	size_t	column = mTextDisplay->getCurrentColumn();
		
	mTextDisplay->write(mChar, row, column);
	if (++row == mTextDisplay->getRow()) {
		row = 0;
		if (++column == mTextDisplay->getColumn()) {
			column = 0;
			mTextDisplay->clear();
		}
	}
	mTextDisplay->setCursorPosition(row, column);
}

bool	operator == (const CommandDefault &lhs [[maybe_unused]], const char &rhs) {
	return std::isprint(rhs);
}

bool	operator == (const char &lhs, const CommandDefault &rhs) {
	return rhs == lhs;
}

}