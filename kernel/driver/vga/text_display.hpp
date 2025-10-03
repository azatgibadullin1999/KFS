/**
 * @file text_display.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef KFS_KERNEL_DRIVER_VGA_SERVICE_IMPL_TEXT_DISPLAY_HPP
# define KFS_KERNEL_DRIVER_VGA_SERVICE_IMPL_TEXT_DISPLAY_HPP

# include <stdint.h>
# include <stddef.h>
# include "driver/utils/port.hpp"
# include "driver/common_interface/text_display.hpp"

namespace kfs::driver::vga {

class VGATextDisplay : public kfs::driver::interface::ITextDisplay {
public:
	VGATextDisplay(const size_t &column_size, const size_t &row_size) :
	ITextDisplay{ column_size, row_size },
	_buffer{ reinterpret_cast<uint16_t*>(0xB8000) },
	_color{ _vga_entry_color(EColor::CYAN, EColor::BLACK) },
	_port1{ 0x3D4 },
	_port2{ 0x3D5 } {
		VGATextDisplay::clear();
	}
	
	VGATextDisplay() :
	VGATextDisplay{25, 80} { }

	void write(char character, size_t row, size_t column) override;
	char read(size_t row, size_t column) override;

	void clear() override;

	bool set_cursor_position(size_t row, size_t column) override;

	void update_cursor_position() override;

	void set_color(EColor color) override;

private:
	void _update_cursor(int row, int column);
	void _enable_cursor(uint8_t cursor_start, uint8_t cursor_end);
	void _disable_cursor();
	static uint8_t _vga_entry_color(enum EColor fg, enum EColor bg) { return fg | bg << 4; }
	static uint16_t _vga_entry(unsigned char uc, uint8_t color) { return (uint16_t) uc | (uint16_t) color << 8; }

	uint16_t* _buffer;
	uint8_t _color;
	const kfs::driver::utils::PortByte	_port1;
	const kfs::driver::utils::PortByte	_port2;
};

}

#endif // KFS_KERNEL_DRIVER_VGA_SERVICE_IMPL_TEXT_DISPLAY_HPP
