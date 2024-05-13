/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_default.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:17:22 by larlena           #+#    #+#             */
/*   Updated: 2024/04/15 13:16:12 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command_default.hpp"

namespace kfs::driver::common {

void	CommandDefault::execute() {
	if (!kfs::isprint(mCharacter))
			return;
		size_t	row = mTextMode->getCurrentRow();
		size_t	column = mTextMode->getCurrentColumn();
		
		mTextMode->write(mCharacter, row, column);
		if (++row == mTextMode->getRow()) {
			row = 0;
			if (++column == mTextMode->getColumn()) {
				column = 0;
				mTextMode->clear();
			}
		}
	mTextMode->setCursorPosition(row, column);
}

}