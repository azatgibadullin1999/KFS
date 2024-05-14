/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_scroll.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 01:51:01 by larlena           #+#    #+#             */
/*   Updated: 2024/05/17 18:41:23 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_SCROLL_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_SCROLL_HPP__

# include "command_textdisplay.hpp"

namespace kfs::driver::common {

class CommandPressScroll final : public kfs::interface::CommandTextDisplay<CommandPressScroll> {
public:
	using CommandTextDisplay::CommandTextDisplay;
	using CommandTextDisplay::operator==;
	using CommandTextDisplay::operator=;
	void	execute() override;
};

}

#endif // __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_SCROLL_HPP__
