/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_scroll.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 01:51:01 by larlena           #+#    #+#             */
/*   Updated: 2024/04/17 14:20:03 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_SCROLL_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_SCROLL_HPP__

# include "common/command.hpp"
# include "driver/common_interface/textmode.hpp"

namespace kfs::driver::common {

class CommandPressScroll final : public kfs::interface::ICommand {
public:
	CommandPressScroll(kfs::driver::interface::ITextMode *textMode) :
	mTextMode(textMode) { }

	void	execute() override;
private:
	kfs::driver::interface::ITextMode *mTextMode;
};

}

#endif // __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_SCROLL_HPP__
