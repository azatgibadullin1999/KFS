/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_newline.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 01:16:34 by larlena           #+#    #+#             */
/*   Updated: 2024/05/17 18:41:29 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_NEWLINE_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_NEWLINE_HPP__

# include <stddef.h>
# include "command_textdisplay.hpp"

namespace kfs::driver::common {

class CommandPressNewLine final : public kfs::interface::CommandTextDisplay<CommandPressNewLine> {
public:
	using CommandTextDisplay::CommandTextDisplay;
	using CommandTextDisplay::operator==;
	using CommandTextDisplay::operator=;
	void	execute() override;
};

}

#endif // __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_NEWLINE_HPP__
