/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_newline_auto_scroll.hpp              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:15:16 by larlena           #+#    #+#             */
/*   Updated: 2024/05/17 18:41:33 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_NEWLINE_AUTO_SCROLL_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_NEWLINE_AUTO_SCROLL_HPP__

# include <stddef.h>
# include "command_textdisplay.hpp"

namespace kfs::driver::common {

class CommandPressNewLineAutoScroll final : public kfs::interface::CommandTextDisplay<CommandPressNewLineAutoScroll> {
public:
	using CommandTextDisplay::CommandTextDisplay;
	using CommandTextDisplay::operator==;
	using CommandTextDisplay::operator=;
	void	execute() override;
};

}

#endif // __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_NEWLINE_AUTO_SCROLL_HPP__
