/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_press_backspace.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:47:48 by larlena           #+#    #+#             */
/*   Updated: 2024/04/17 14:20:03 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESSBACK_SPACE_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESSBACK_SPACE_HPP__

# include <stddef.h>
# include "common/command.hpp"
# include "driver/common_interface/textmode.hpp"

namespace kfs::driver::common {

class CommandPressBackspace final : public kfs::interface::ICommand {
public:
	CommandPressBackspace(kfs::driver::interface::ITextMode *textMode) :
	mTextMode(textMode) { }

	void	execute() override;
private:
	kfs::driver::interface::ITextMode *mTextMode;
};

}

#endif // __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESSBACK_SPACE_HPP__
