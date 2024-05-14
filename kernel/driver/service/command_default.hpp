/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_default.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:45:49 by larlena           #+#    #+#             */
/*   Updated: 2024/05/17 18:41:42 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_COMMAND_DEFAULT_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_COMMAND_DEFAULT_HPP__

# include "command_textdisplay.hpp"
# include "utils/libft.hpp"

namespace kfs::driver::common {

class CommandDefault final : public kfs::interface::CommandTextDisplay<CommandDefault> {
public:
	using CommandTextDisplay::CommandTextDisplay;
	using CommandTextDisplay::operator=;
	void	execute() override;
};

}

#endif // __KFS_KERNEL_DRIVER_SERVICE_COMMAND_DEFAULT_HPP__