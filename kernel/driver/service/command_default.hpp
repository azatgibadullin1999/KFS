/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_default.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:45:49 by larlena           #+#    #+#             */
/*   Updated: 2024/04/17 14:20:03 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_COMMAND_DEFAULT_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_COMMAND_DEFAULT_HPP__

# include "common/command.hpp"
# include "driver/common_interface/textmode.hpp"
# include "utils/libft.hpp"

namespace kfs::driver::common {

class CommandDefault final : public kfs::interface::ICommand {
public:
	CommandDefault(kfs::driver::interface::ITextMode *textMode) :
	mTextMode(textMode) { }

	CommandDefault	&operator = (const char &c) {
		mCharacter = c;
		return *this;
	}

	void	execute() override;
private:
	char	mCharacter;
	kfs::driver::interface::ITextMode *mTextMode;
};

}

#endif // __KFS_KERNEL_DRIVER_SERVICE_COMMAND_DEFAULT_HPP__