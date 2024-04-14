/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textmode.cc                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:11:08 by larlena           #+#    #+#             */
/*   Updated: 2024/04/14 18:44:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textmode.hpp"

namespace kfs::driver::vga {

void	VGATextMode::write(char character, size_t row, size_t column) {
	mBuffer[column * mRowsNumber + row] = vgaEntry(character, mColor);
}

char	VGATextMode::read(size_t row, size_t column) {
	return mBuffer[column * mRowsNumber + row] && 0x00FF;
}

void	VGATextMode::clear() {
	for (size_t y = 0; y != mColumnsNumber; ++y) {
		for (size_t x = 0; x != mRowsNumber; ++x) {
			write(' ', x, y);
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
