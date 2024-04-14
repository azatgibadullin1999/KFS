/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textmode.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:30:28 by larlena           #+#    #+#             */
/*   Updated: 2024/04/14 11:06:52 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KERNEL_DRIVER_VGA_SERVICE_IMPL_TEXTMODE_HPP__
# define __KERNEL_DRIVER_VGA_SERVICE_IMPL_TEXTMODE_HPP__

# include <stdint.h>
# include <stddef.h>
# include "utils/libft.h"
# include "driver/utils/port.hpp"
# include "driver/common_interface/textmode.hpp"

namespace kfs::driver::vga {

class VGATextMode : public kfs::driver::interface::ITextMode {
public:
	enum Color {
		VGA_COLOR_BLACK = 0,
		VGA_COLOR_BLUE = 1,
		VGA_COLOR_GREEN = 2,
		VGA_COLOR_CYAN = 3,
		VGA_COLOR_RED = 4,
		VGA_COLOR_MAGENTA = 5,
		VGA_COLOR_BROWN = 6,
		VGA_COLOR_LIGHT_GREY = 7,
		VGA_COLOR_DARK_GREY = 8,
		VGA_COLOR_LIGHT_BLUE = 9,
		VGA_COLOR_LIGHT_GREEN = 10,
		VGA_COLOR_LIGHT_CYAN = 11,
		VGA_COLOR_LIGHT_RED = 12,
		VGA_COLOR_LIGHT_MAGENTA = 13,
		VGA_COLOR_LIGHT_BROWN = 14,
		VGA_COLOR_WHITE = 15,
	};
public:
	VGATextMode(const size_t &sizeOfColumn, const size_t &sizeOfRow) :
	ITextMode(sizeOfColumn, sizeOfRow),
	mBuffer(reinterpret_cast<uint16_t*>(0xB8000)),
	mColor(vgaEntryColor(VGA_COLOR_GREEN, VGA_COLOR_BLACK)),
	mPort1(0x3D4),
	mPort2(0x3D5) {
		clear();
	}
	
	VGATextMode() :
	VGATextMode(25, 80) { }

	void	write(char character, size_t row, size_t column) override;
	char	read(size_t row, size_t column) override;

	void	clear() override;

	bool	setCursorPosition(size_t row, size_t column) override;

	void	setColor(uint8_t color);

private:

	void	updateCursor(int row, int column);
	void	enableCursor(uint8_t cursor_start, uint8_t cursor_end);
	void	disableCursor();
	uint8_t	vgaEntryColor(enum Color fg, enum Color bg) { return fg | bg << 4; }
	uint16_t	vgaEntry(unsigned char uc, uint8_t color) { return (uint16_t) uc | (uint16_t) color << 8; }
private:
	uint16_t* mBuffer;
	uint8_t mColor;
	const kfs::driver::utils::Port	mPort1;
	const kfs::driver::utils::Port	mPort2;
};

}

#endif // __KERNEL_DRIVER_VGA_SERVICE_IMPL_TEXTMODE_HPP__
