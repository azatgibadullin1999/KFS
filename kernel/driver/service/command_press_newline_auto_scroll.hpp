/**
 * @file command_press_newline_auto_scroll.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_NEWLINE_AUTO_SCROLL_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_NEWLINE_AUTO_SCROLL_HPP__

# include <stddef.h>
# include "command_text_display.hpp"

namespace kfs::driver::common {

class CommandPressNewLineAutoScroll final : public kfs::interface::CommandTextDisplay<CommandPressNewLineAutoScroll> {
public:
	using CommandTextDisplay::CommandTextDisplay;
	using CommandTextDisplay::operator==;
	using CommandTextDisplay::operator=;
	void	execute() override;
};

}

#endif // __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_NEWLINE_AUTO_SCROLL_HPP__
