/**
 * @file command_default_auto_scroll.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_COMMAND_DEFAULT_AUTO_SCROLL_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_COMMAND_DEFAULT_AUTO_SCROLL_HPP__

# include "command_text_display.hpp"
# include <cctype>

namespace kfs::driver::common {

class CommandDefaultAutoScroll final : public kfs::interface::CommandTextDisplay<CommandDefaultAutoScroll> {
public:
	using CommandTextDisplay::CommandTextDisplay;
	using CommandTextDisplay::operator=;

	bool	operator == (const char &rhs) const {
		return std::isprint(rhs);
	}

	void	execute() override;
};

}

#endif // __KFS_KERNEL_DRIVER_SERVICE_COMMAND_DEFAULT_AUTO_SCROLL_HPP__
