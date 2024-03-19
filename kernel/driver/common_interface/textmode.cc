/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textmode.cc                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:16:05 by larlena           #+#    #+#             */
/*   Updated: 2024/03/18 22:59:49 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textmode.hpp"

namespace kfs::driver::interface {

bool	ITextMode::setCursorPosition(size_t row, size_t column) {
	if (mColumnsNumber < column && mRowsNumber < row) {
		mColumn = column;
		mRow = row;
		return 0;
	}
	return 1;
}

}
