/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_default.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:17:22 by larlena           #+#    #+#             */
/*   Updated: 2024/05/21 16:22:16 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_default.hpp"

namespace kfs::driver::common {

void	CommandDefault::execute() {
	if (!kfs::isprint(mChar))
			return;
	size_t	row = mTextDisplay->getCurrentRow();
	size_t	column = mTextDisplay->getCurrentColumn();
		
	mTextDisplay->write(mChar, row, column);
	if (++row == mTextDisplay->getRow()) {
		row = 0;
		if (++column == mTextDisplay->getColumn()) {
			column = 0;
			mTextDisplay->clear();
		}
	}
	mTextDisplay->setCursorPosition(row, column);
}

bool	operator == (const CommandDefault &lhs [[maybe_unused]], const char &rhs) {
	return kfs::isprint(rhs);
}

bool	operator == (const char &lhs, const CommandDefault &rhs) {
	return rhs == lhs;
}

}