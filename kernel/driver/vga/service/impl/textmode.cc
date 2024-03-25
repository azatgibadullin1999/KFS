/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textmode.cc                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:11:08 by larlena           #+#    #+#             */
/*   Updated: 2024/03/25 17:21:38 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textmode.hpp"

namespace kfs::driver::vga {

// void	VGATextMode::write(char character) {
// 	putEntry(character, mColor, mRow, mColumn);
// 	if (++mRow == mRowsNumber) {
// 		mRow = 0;
// 		if (++mColumn == mColumnsNumber) {
// 			mColumn = 0;
// 			clear();
// 		}
// 	}
// }

// void	VGATextMode::write(const char* data, size_t size) {
// 	for (size_t i = 0; i < size; i++)
// 		write(data[i]);
// }

// void	VGATextMode::write(const char* data) {
// 	write(data, ft_strlen(data));
// }

// void	VGATextMode::write(char character, size_t row, size_t column) {
// 	if (mRowsNumber > row && mColumnsNumber > column) {
// 		putEntry(character, mColor, row, column);
// 	}
// }

VGATextMode::IProxyScreenWriter	*VGATextMode::ProxyVGAScreenWriter::put(const char &character) {
	*mBuffer = vgaEntry(character, 0);
}

// const VGATextMode::IProxyScreenWriter	&VGATextMode::ProxyVGAScreenWriter::operator = (const char &character) const {
// }

VGATextMode::IProxyScreenWriter	*VGATextMode::ProxyVGATextMode::row(size_t row) {
	static ProxyVGAScreenWriter	screen;

	screen = mBuffer + row;
	if (row > mRowsNumber) {
		screen = mBuffer;
	}

	return &screen;
}

VGATextMode::IProxyTextMode	*VGATextMode::column(size_t column) {
	static ProxyVGATextMode	proxy = ProxyVGATextMode(mRowsNumber);

	proxy = mBuffer + (column * mRowsNumber);
	if (column > mColumnsNumber) {
		proxy = mBuffer;
	}
	return &proxy;
}

// const VGATextMode::IProxyTextMode	*VGATextMode::operator [] (size_t column) const {
// }

void	VGATextMode::clear() {
	for (size_t y = 0; y != mColumnsNumber; ++y) {
		for (size_t x = 0; x != mRowsNumber; ++x) {
			putEntry(' ', mColor, x, y);
		}
	}
}

bool	VGATextMode::setCursorPosition(size_t row, size_t column) {
	auto&&	retValue = ITextMode::setCursorPosition(row, column);
	
	if (!retValue)
		updateCursor(mRow, mColumn);
	return retValue;
}



void	VGATextMode::setColor(uint8_t color) {
	mColor = color;
}
	
void	VGATextMode::putEntry(char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * mRowsNumber + x;
	mBuffer[index] = vga_entry(c, color);
}


// uint8_t VGATextMode::vga_entry_color(enum Color fg, enum Color bg) {
// 	return fg | bg << 4;
// }

// uint16_t VGATextMode::vga_entry(unsigned char uc, uint8_t color) {
// 	return (uint16_t) uc | (uint16_t) color << 8;
// }


void	VGATextMode::updateCursor(int row, int column) {
	uint16_t pos = column * mRowsNumber + row;

	mPort1.write(0x0F);
	mPort2.write((uint8_t) (pos & 0xFF));
	mPort1.write(0x0E);
	mPort2.write((uint8_t) ((pos >> 8) & 0xFF));
}

void	VGATextMode::enableCursor(uint8_t cursor_start, uint8_t cursor_end) {
	mPort1.write(0x0A);
	mPort2.write((mPort2.read() & 0xC0) | cursor_start);

	mPort1.write(0x0B);
	mPort2.write((mPort2.read() & 0xE0) | cursor_end);
}

void	VGATextMode::disableCursor() {
	mPort1.write(0x0A);
	mPort2.write(0x20);
}

}
