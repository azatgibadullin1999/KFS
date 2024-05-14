/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_display.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:30:28 by larlena           #+#    #+#             */
/*   Updated: 2024/05/17 20:27:14 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KERNEL_DRIVER_VGA_SERVICE_IMPL_TEXT_DISPLAY_HPP__
# define __KERNEL_DRIVER_VGA_SERVICE_IMPL_TEXT_DISPLAY_HPP__

# include <stdint.h>
# include <stddef.h>
# include "utils/libft.hpp"
# include "driver/utils/port.hpp"
# include "driver/common_interface/text_display.hpp"

namespace kfs::driver::vga {

class VGATextDisplay : public kfs::driver::interface::ITextDisplay {
public:
	VGATextDisplay(const size_t &sizeOfColumn, const size_t &sizeOfRow) :
	ITextDisplay(sizeOfColumn, sizeOfRow),
	mBuffer(reinterpret_cast<uint16_t*>(0xB8000)),
	mColor(vgaEntryColor(CYAN, BLACK)),
	mPort1(0x3D4),
	mPort2(0x3D5) {
		clear();
	}
	
	VGATextDisplay() :
	VGATextDisplay(25, 80) { }

	void	write(char character, size_t row, size_t column) override;
	char	read(size_t row, size_t column) override;

	void	clear() override;

	bool	setCursorPosition(size_t row, size_t column) override;

	void	updateCursorPosition() override;

	void	setColor(Color color);

private:
	void	updateCursor(int row, int column);
	void	enableCursor(uint8_t cursor_start, uint8_t cursor_end);
	void	disableCursor();
	uint8_t	vgaEntryColor(enum Color fg, enum Color bg) { return fg | bg << 4; }
	uint16_t	vgaEntry(unsigned char uc, uint8_t color) { return (uint16_t) uc | (uint16_t) color << 8; }

private:
	uint16_t* mBuffer;
	uint8_t mColor;
	const kfs::driver::utils::PortByte	mPort1;
	const kfs::driver::utils::PortByte	mPort2;
};

}

#endif // __KERNEL_DRIVER_VGA_SERVICE_IMPL_TEXT_DISPLAY_HPP__
