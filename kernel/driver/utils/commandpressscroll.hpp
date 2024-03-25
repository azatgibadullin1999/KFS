/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commandpressscroll.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 01:51:01 by larlena           #+#    #+#             */
/*   Updated: 2024/03/25 02:15:44 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_UTILS_COMMANDPRESSSCROLL_HPP__
# define __KFS_KERNEL_DRIVER_UTILS_COMMANDPRESSSCROLL_HPP__

# include "../../interface/command.hpp"
# include "../common_interface/textmode.hpp"

namespace kfs::driver::common {

class CommandPressScroll : public kfs::interface::ICommand {
public:
	CommandPressScroll(kfs::driver::interface::ITextMode *textMode) :
	mTextMode(textMode) { }

	void	execute() override {
		size_t	it;

		if (mColumn == 0)
			return ;
		for (it = 0; it < mRowsNumber * (mColumnsNumber - 1); ++it) {
			mBuffer[it] = mBuffer[it + mRowsNumber];
		}
		for (; it < mRowsNumber * mColumnsNumber; ++it) {
			mBuffer[it] = ' ';
		}
		mColumn -= 1;
	}
private:
	kfs::driver::interface::ITextMode *mTextMode;
};

}

#endif // __KFS_KERNEL_DRIVER_UTILS_COMMANDPRESSSCROLL_HPP__
