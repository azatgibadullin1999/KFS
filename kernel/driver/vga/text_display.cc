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

namespace kfs::driver::vga {

void	VGATextDisplay::write(char character, size_t row, size_t column) {
	mBuffer[column * mRowsNumber + row] = vgaEntry(character, mColor);
}

char	VGATextDisplay::read(size_t row, size_t column) {
	return static_cast<char>(mBuffer[column * mRowsNumber + row] & 0x00FF);
}

void	VGATextDisplay::clear() {
	for (size_t y = 0; y != mColumnsNumber; ++y) {
		for (size_t x = 0; x != mRowsNumber; ++x) {
			write(' ', x, y);
		}
	}
}

bool	VGATextDisplay::setCursorPosition(size_t row, size_t column) {
	auto&&	retValue = ITextDisplay::setCursorPosition(row, column);
	return retValue;
}

void	VGATextDisplay::updateCursorPosition() {
	updateCursor(mRow, mColumn);
}


void	VGATextDisplay::setColor(Color color) {
	mColor = color;
}

void	VGATextDisplay::updateCursor(int row, int column) {
	uint16_t pos = column * mRowsNumber + row;

	mPort1.write(0x0F);
	mPort2.write((uint8_t) (pos & 0xFF));
	mPort1.write(0x0E);
	mPort2.write((uint8_t) ((pos >> 8) & 0xFF));
}

void	VGATextDisplay::enableCursor(uint8_t cursor_start, uint8_t cursor_end) {
	mPort1.write(0x0A);
	mPort2.write((mPort2.read() & 0xC0) | cursor_start);

	mPort1.write(0x0B);
	mPort2.write((mPort2.read() & 0xE0) | cursor_end);
}

void	VGATextDisplay::disableCursor() {
	mPort1.write(0x0A);
	mPort2.write(0x20);
}

}
