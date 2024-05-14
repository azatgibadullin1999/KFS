/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_tab.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:17:56 by larlena           #+#    #+#             */
/*   Updated: 2024/05/17 19:31:19 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_TAB_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_TAB_HPP__

# include <stdint.h>
# include <stddef.h>
# include "command_textdisplay.hpp"

namespace kfs::driver::common {

class CommandPressTab final : public kfs::interface::CommandTextDisplay<CommandPressTab> {
public:
	CommandPressTab(char c,kfs::driver::interface::ITextDisplay *textDisplay, size_t tabSize) :
	CommandTextDisplay(c, textDisplay),
	mTabSize(tabSize) { }
	using CommandTextDisplay::operator==;
	using CommandTextDisplay::operator=;

	void	execute() override;
private:
	size_t	mTabSize;
};

}

#endif // __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_TAB_HPP__
