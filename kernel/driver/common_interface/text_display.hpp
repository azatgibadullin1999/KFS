/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_display.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:20:14 by larlena           #+#    #+#             */
/*   Updated: 2024/05/17 20:13:00 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_COMMON_INTERFACE_TEXT_DISPLAY__
# define __KFS_KERNEL_DRIVER_COMMON_INTERFACE_TEXT_DISPLAY__

# include <stdint.h>
# include <stddef.h>

namespace kfs::driver::interface {

class ITextDisplay {
public:
	enum Color {
		BLACK = 0,
		BLUE = 1,
		GREEN = 2,
		CYAN = 3,
		RED = 4,
		MAGENTA = 5,
		BROWN = 6,
		LIGHT_GREY = 7,
		DARK_GREY = 8,
		LIGHT_BLUE = 9,
		LIGHT_GREEN = 10,
		LIGHT_CYAN = 11,
		LIGHT_RED = 12,
		LIGHT_MAGENTA = 13,
		LIGHT_BROWN = 14,
		WHITE = 15,
	};
public:
	ITextDisplay(const size_t &columnsNumber, const size_t &rowsNumber) :
	mColumnsNumber(columnsNumber),
	mRowsNumber(rowsNumber),
	mColumn(0),
	mRow(0) { }

	virtual void	write(char, size_t row, size_t column) = 0;
	virtual char	read(size_t row, size_t column) = 0;

	virtual void	clear() = 0;

	virtual bool	setCursorPosition(size_t row, size_t column) = 0;

	virtual void	updateCursorPosition() = 0;

	virtual void	setColor(Color color) = 0;

	const size_t	&getCurrentColumn() const {
		return mColumn;
	}
	const size_t	&getCurrentRow() const {
		return mRow;
	}
	const size_t	&getColumn() const {
		return mColumnsNumber;
	}
	const size_t	&getRow() const {
		return mRowsNumber;
	}
protected:
	const size_t mColumnsNumber;
	const size_t mRowsNumber;
	size_t mColumn;
	size_t mRow;
};


}

#endif // __KFS_KERNEL_DRIVER_COMMON_INTERFACE_TEXT_DISPLAY__
