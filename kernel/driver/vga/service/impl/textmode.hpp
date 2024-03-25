/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textmode.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:30:28 by larlena           #+#    #+#             */
/*   Updated: 2024/03/25 18:44:06 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KERNEL_DRIVER_VGA_SERVICE_IMPL_TEXTMODE_HPP__
# define __KERNEL_DRIVER_VGA_SERVICE_IMPL_TEXTMODE_HPP__

# include <stdint.h>
# include <stddef.h>
# include "../../../../utils/libft.h"
# include "../../../utils/port.hpp"
# include "../../../common_interface/keyboard_decoder.hpp"
# include "../../../common_interface/textmode.hpp"

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

	class ProxyVGAScreenWriter : public ITextMode::IProxyScreenWriter {
	public:
		// ProxyVGAScreenWriter(uint16_t *buff) :
		// mBuffer(buff) { }

		ProxyVGAScreenWriter	&operator = (uint16_t *buff) {
			mBuffer = buff;
		}


		IProxyScreenWriter	*put(const char &c) override;

		// const IProxyScreenWriter	&operator = (const char &c) const  override;
	private:
		
		uint8_t vgaEntryColor(enum Color fg, enum Color bg) {
			return fg | bg << 4;
		}
		uint16_t vgaEntry(unsigned char uc, uint8_t color) {
			return (uint16_t) uc | (uint16_t) color << 8;
		}

	private:
		uint16_t* mBuffer;
	};

	class ProxyVGATextMode : public ITextMode::IProxyTextMode {
	public:
		ProxyVGATextMode(size_t rowsNumber) :
		mRowsNumber(rowsNumber) { }

		ProxyVGATextMode	&operator = (uint16_t *buff) {
			mBuffer = buff;
		}

		virtual IProxyScreenWriter	*row(size_t row) override;
		// virtual const IProxyScreenWriter	&operator [] (size_t row) const override;
	private:
		uint16_t	*mBuffer;
		size_t	mRowsNumber;
	};
public:
	VGATextMode(const size_t &sizeOfColumn, const size_t &sizeOfRow) :
	ITextMode(sizeOfColumn, sizeOfRow),
	mColor(vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK)),
	mBuffer(reinterpret_cast<uint16_t*>(0xB8000)),
	mProxy(mBuffer),
	mPort1(0x3D4),
	mPort2(0x3D5) {
		clear();
	}
	
	VGATextMode() :
	VGATextMode(25, 80) { }

	// void	write(char character) override;
	// void	write(const char *data) override;
	// void	write(const char *data, size_t size) override;
	// void	write(char character, size_t row, size_t column) override;

	void	clear() override;

	bool	setCursorPosition(size_t column, size_t row) override;

	void	setColor(uint8_t color);


	IProxyTextMode	*column(size_t column) override;
	// const IProxyTextMode	&operator [] (size_t column) const override;

private:
	void	putEntry(char c, uint8_t color, size_t x, size_t y);
	uint8_t vga_entry_color(enum Color fg, enum Color bg);
	uint16_t vga_entry(unsigned char uc, uint8_t color);
	// fuinctions for cursore support
	void	updateCursor(int row, int column);
	void	enableCursor(uint8_t cursor_start, uint8_t cursor_end);
	void	disableCursor();
private:
	uint16_t* mBuffer;
	uint8_t mColor;
	ProxyVGATextMode	mProxy;
	const kfs::driver::utils::Port	mPort1;
	const kfs::driver::utils::Port	mPort2;
};

}

#endif // __KERNEL_DRIVER_VGA_SERVICE_IMPL_TEXTMODE_HPP__
