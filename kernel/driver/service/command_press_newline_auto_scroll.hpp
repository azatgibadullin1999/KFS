/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_newline_auto_scroll.hpp              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:15:16 by larlena           #+#    #+#             */
/*   Updated: 2024/05/12 17:16:06 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_NEWLINE_AUTO_SCROLL_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_NEWLINE_AUTO_SCROLL_HPP__

# include <stddef.h>
# include "common/command.hpp"
# include "driver/common_interface/textmode.hpp"

namespace kfs::driver::common {

class CommandPressNewLineAutoScroll final : public kfs::interface::ICommand {
public:
	CommandPressNewLineAutoScroll(kfs::driver::interface::ITextMode *textMode) :
	mTextMode(textMode) { }

	void	execute() override;
private:
	kfs::driver::interface::ITextMode	*mTextMode;
};

}

#endif // __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_NEWLINE_AUTO_SCROLL_HPP__
