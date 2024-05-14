/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_backspace.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:47:48 by larlena           #+#    #+#             */
/*   Updated: 2024/05/17 20:41:08 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_BACKSPACE_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_BACKSPACE_HPP__

# include <stddef.h>
# include "command_textdisplay.hpp"

namespace kfs::driver::common {

class CommandPressBackspace final : public kfs::interface::CommandTextDisplay<CommandPressBackspace> {
public:
	using CommandTextDisplay::CommandTextDisplay;
	using CommandTextDisplay::operator==;
	using CommandTextDisplay::operator=;
	void	execute() override;
};

}

#endif // __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_BACKSPACE_HPP__
