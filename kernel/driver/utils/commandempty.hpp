/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commandempty.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:32:15 by larlena           #+#    #+#             */
/*   Updated: 2024/03/26 20:34:10 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_UTILS_COMMANDEMPTY_HPP__
# define __KFS_KERNEL_DRIVER_UTILS_COMMANDEMPTY_HPP__

# include "../../interface/command.hpp"
# include "../common_interface/textmode.hpp"

namespace kfs::driver::common {

class CommandEmpty : public kfs::interface::ICommand {
	void	execute() override { }
};

}

#endif // __KFS_KERNEL_DRIVER_UTILS_COMMANDEMPTY_HPP__