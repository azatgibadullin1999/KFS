/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_display.cc                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:16:05 by larlena           #+#    #+#             */
/*   Updated: 2024/05/17 20:13:10 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "text_display.hpp"

namespace kfs::driver::interface {

bool	ITextDisplay::setCursorPosition(size_t row, size_t column) {
	if (column < mColumnsNumber && row < mRowsNumber) {
		mColumn = column;
		mRow = row;
		return false;
	}
	return true;
}

}
