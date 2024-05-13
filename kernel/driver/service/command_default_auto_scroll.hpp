/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_default_auto_scroll.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:37:02 by larlena           #+#    #+#             */
/*   Updated: 2024/05/12 16:38:08 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_COMMAND_DEFAULT_AUTO_SCROLL_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_COMMAND_DEFAULT_AUTO_SCROLL_HPP__

# include "common/command.hpp"
# include "driver/common_interface/textmode.hpp"
# include "utils/libft.hpp"

namespace kfs::driver::common {

class CommandDefaultAutoScroll final : public kfs::interface::ICommand {
public:
	CommandDefaultAutoScroll(kfs::driver::interface::ITextMode *textMode) :
	mTextMode(textMode) { }

	CommandDefaultAutoScroll	&operator = (const char &c) {
		mCharacter = c;
		return *this;
	}

	void	execute() override;
private:
	char	mCharacter;
	kfs::driver::interface::ITextMode *mTextMode;
};

}

#endif // __KFS_KERNEL_DRIVER_SERVICE_COMMAND_DEFAULT_AUTO_SCROLL_HPP__
