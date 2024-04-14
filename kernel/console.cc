/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.cc                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:42:15 by larlena           #+#    #+#             */
/*   Updated: 2024/04/13 12:58:01 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console.hpp"

void	kfs::Console::doWork() {
	mScanCodeBuff = mKayboard->read();
	if (mScanCodeBuff == 0xFF) {
		return;
	}
	mCharBuff = mDecoder->scan(mScanCodeBuff);
	mProcessor->process(mCharBuff)->execute();
}
