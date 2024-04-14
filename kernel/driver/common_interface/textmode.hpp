/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textmode.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:20:14 by larlena           #+#    #+#             */
/*   Updated: 2024/04/13 12:37:52 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DIRVER_COMMON_INTERFACE_TEXTMODE__
# define __KFS_KERNEL_DIRVER_COMMON_INTERFACE_TEXTMODE__

# include <stdint.h>
# include <stddef.h>

namespace kfs::driver::interface {

class ITextMode {
public:
	ITextMode(const size_t &columnsNumber, const size_t &rowsNumber) :
	mColumnsNumber(columnsNumber),
	mRowsNumber(rowsNumber),
	mColumn(0),
	mRow(0) { }

	virtual void	write(char, size_t row, size_t column) = 0;
	virtual char	read(size_t row, size_t column) = 0;

	virtual void	clear() = 0;

	virtual bool	setCursorPosition(size_t row, size_t column) = 0;
	
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

#endif // __KFS_KERNEL_DIRVER_COMMON_INTERFACE_TEXTMODE__
