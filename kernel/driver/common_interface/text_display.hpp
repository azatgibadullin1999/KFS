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

#ifndef __KFS_KERNEL_DRIVER_COMMON_INTERFACE_TEXT_DISPLAY__
# define __KFS_KERNEL_DRIVER_COMMON_INTERFACE_TEXT_DISPLAY__

# include <cstddef>

namespace kfs::driver::interface {

class ITextDisplay {
public:
	enum EColor {
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

	ITextDisplay(const size_t &columns_umber, const size_t &rows_umber) :
	_columns_number{ columns_umber },
	_rows_number{ rows_umber },
	_column{ 0 },
	_row{ 0 } { }

	virtual void	write(char, size_t row, size_t column) = 0;
	virtual char	read(size_t row, size_t column) = 0;

	virtual void	clear() = 0;

	virtual bool	set_cursor_position(size_t row, size_t column) = 0;

	virtual void	update_cursor_position() = 0;

	virtual void	set_color(EColor color) = 0;

	const size_t	&get_current_column() const {
		return _column;
	}
	const size_t	&get_current_row() const {
		return _row;
	}
	const size_t	&get_column() const {
		return _columns_number;
	}
	const size_t	&get_row() const {
		return _rows_number;
	}
protected:
	const size_t _columns_number;
	const size_t _rows_number;
	size_t _column;
	size_t _row;
};


}

#endif // __KFS_KERNEL_DRIVER_COMMON_INTERFACE_TEXT_DISPLAY__
