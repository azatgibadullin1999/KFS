/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textmode.cc                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:11:08 by larlena           #+#    #+#             */
/*   Updated: 2024/03/19 19:59:02 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textmode.hpp"

namespace kfs::driver::vga {

void	VGATextMode::write(char c) {
	if (c == '\n') {
		pressNewLine();
	} else if (c == '\b') {
		pressBackSpace();
	} else if (c == '\t') {
		pressTab();
	} else if ((uint8_t)c == interface::IKeyboardDecoder::DOWN) {
		pressScroll();
	} else if (ft_isprint(c)) {
		putEntry(c, mColor, mRow, mColumn);
		if (++mRow == mRowsNumber) {
			mRow = 0;
			if (++mColumn == mColumnsNumber) {
				mColumn = 0;
				clear();
			}
		}
	}
	update_cursor(mRow, mColumn);
}

void	VGATextMode::write(const char* data, size_t size) {
	for (size_t i = 0; i < size; i++)
		write(data[i]);
}

void	VGATextMode::write(const char* data) {
	write(data, ft_strlen(data));
}

void	VGATextMode::clear() {
	for (size_t y = 0; y != mColumnsNumber; ++y) {
		for (size_t x = 0; x != mRowsNumber; ++x) {
			putEntry(' ', mColor, x, y);
		}
	}
}

void	VGATextMode::pressBackSpace() {
	if (mRow == 0 && mColumn != 0) {
		mColumn -= 1;
		mRow = mRowsNumber;
	}
	mRow -= 1;
	putEntry(' ', mColor, mRow, mColumn);
}

void	VGATextMode::pressNewLine() {
	mRow = 0;
	if (++mColumn == mColumnsNumber) {
		mColumn = 0;
		clear();
	}
}

void	VGATextMode::pressTab() {
	size_t	tabSize = 8;

	mRow += tabSize - (mRow % tabSize);
}

void	VGATextMode::pressScroll() {
	size_t	it;

	if (mColumn == 0)
		return ;
	for (it = 0; it < mRowsNumber * (mColumnsNumber - 1); ++it) {
		mBuffer[it] = mBuffer[it + mRowsNumber];
	}
	for (; it < mRowsNumber * mColumnsNumber; ++it) {
		mBuffer[it] = ' ';
	}
	mColumn -= 1;
}

bool	VGATextMode::setCursorPosition(size_t row, size_t column) {
	return ITextMode::setCursorPosition(row, column);
}



void	VGATextMode::setColor(uint8_t color) {
	mColor = color;
}
	
void	VGATextMode::putEntry(char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * mRowsNumber + x;
	mBuffer[index] = vga_entry(c, color);
}


uint8_t VGATextMode::vga_entry_color(enum Color fg, enum Color bg) {
	return fg | bg << 4;
}

uint16_t VGATextMode::vga_entry(unsigned char uc, uint8_t color) {
	return (uint16_t) uc | (uint16_t) color << 8;
}


void	VGATextMode::update_cursor(int row, int column) {
	uint16_t pos = column * mRowsNumber + row;

	mPort1.write(0x0F);
	mPort2.write((uint8_t) (pos & 0xFF));
	mPort1.write(0x0E);
	mPort2.write((uint8_t) ((pos >> 8) & 0xFF));
}

void	VGATextMode::enable_cursor(uint8_t cursor_start, uint8_t cursor_end) {
	mPort1.write(0x0A);
	mPort2.write((mPort2.read() & 0xC0) | cursor_start);

	mPort1.write(0x0B);
	mPort2.write((mPort2.read() & 0xE0) | cursor_end);
}

void	VGATextMode::disable_cursor() {
	mPort1.write(0x0A);
	mPort2.write(0x20);
}

}
