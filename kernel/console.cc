/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.cc                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:42:15 by larlena           #+#    #+#             */
/*   Updated: 2024/04/16 16:47:03 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.hpp"

void	kfs::Console::process() {
	mScanCodeBuff = mKeyboard->read();
	if (mScanCodeBuff == 0xFF) {
		return;
	}
	mCharBuff = mDecoder->scan(mScanCodeBuff);
	mProcessor->process(mCharBuff)->execute();
}

void	kfs::Console::write(char c) {
	mProcessor->process(c)->execute();
}

void	kfs::Console::write(const char *str) {
	for (size_t it = 0; str[it]; ++it) {
		mProcessor->process(str[it])->execute();
	}
}
