/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_default_auto_scroll.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:37:02 by larlena           #+#    #+#             */
/*   Updated: 2024/05/17 18:55:34 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_COMMAND_DEFAULT_AUTO_SCROLL_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_COMMAND_DEFAULT_AUTO_SCROLL_HPP__

# include "command_textdisplay.hpp"
# include "utils/libft.hpp"

namespace kfs::driver::common {

class CommandDefaultAutoScroll final : public kfs::interface::CommandTextDisplay<CommandDefaultAutoScroll> {
public:
	using CommandTextDisplay::CommandTextDisplay;
	using CommandTextDisplay::operator=;

	bool	operator == (const char &rhs) const {
		return kfs::isprint(rhs);
	}

	void	execute() override;
};

}

#endif // __KFS_KERNEL_DRIVER_SERVICE_COMMAND_DEFAULT_AUTO_SCROLL_HPP__
