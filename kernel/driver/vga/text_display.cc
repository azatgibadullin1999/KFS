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
	_buffer[(column * _rows_number) + row] = _vga_entry(character, _color);
}

char	VGATextDisplay::read(size_t row, size_t column) {
	return static_cast<char>(_buffer[(column * _rows_number) + row] & 0x00FF);
}

void	VGATextDisplay::clear() {
	for (size_t y = 0; y != _columns_number; ++y) {
		for (size_t x = 0; x != _rows_number; ++x) {
			write(' ', x, y);
		}
	}
}

bool	VGATextDisplay::set_cursor_position(size_t row, size_t column) {
	return ITextDisplay::set_cursor_position(row, column);
}

void	VGATextDisplay::update_cursor_position() {
	_update_cursor(_row, _column);
}


void	VGATextDisplay::set_color(EColor color) {
	_color = color;
}

void	VGATextDisplay::_update_cursor(int row, int column) {
	uint16_t pos = (column * _rows_number) + row;

	_port1.write(0x0F);
	_port2.write((uint8_t) (pos & 0xFF));
	_port1.write(0x0E);
	_port2.write((uint8_t) ((pos >> 8) & 0xFF));
}

void	VGATextDisplay::_enable_cursor(uint8_t cursor_start, uint8_t cursor_end) {
	_port1.write(0x0A);
	_port2.write((_port2.read() & 0xC0) | cursor_start);

	_port1.write(0x0B);
	_port2.write((_port2.read() & 0xE0) | cursor_end);
}

void	VGATextDisplay::_disable_cursor() {
	_port1.write(0x0A);
	_port2.write(0x20);
}

}
