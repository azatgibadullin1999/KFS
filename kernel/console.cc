/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.cc                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:42:15 by larlena           #+#    #+#             */
/*   Updated: 2024/05/17 22:52:16 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.hpp"

void	kfs::Console::process() {
	mScanCodeBuff = mKeyboard->read();
	if (mScanCodeBuff == 0xFF) {
		return;
	}
	mProcessor->process(mCharBuff);
	mTextDisplay->updateCursorPosition();
}

void	kfs::Console::write(char c) {
	mProcessor->process(c);
	mTextDisplay->updateCursorPosition();
}

void	kfs::Console::write(const char *str) {
	for (size_t it = 0; str[it]; ++it) {
		mProcessor->process(str[it]);
	}
	mTextDisplay->updateCursorPosition();
}

char	kfs::Console::read() {
	mScanCodeBuff = mKeyboard->read();
	if (mScanCodeBuff == 0xFF) {
		return -1;
	}
	return mScanCodeBuff;
}

char	kfs::Console::readBlocking() {
	char	buff = -1;

	while (buff == -1) {
		buff = read();
	}

	return buff;
}
