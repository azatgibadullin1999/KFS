/**
 * @file command_press_newline.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_NEWLINE_HPP
# define KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_NEWLINE_HPP

# include <cstddef>
# include "command_text_display.hpp"

namespace kfs::driver::common {

class CommandPressNewLine final : public kfs::interface::CommandTextDisplay<CommandPressNewLine> {
public:
	using CommandTextDisplay::CommandTextDisplay;
	using CommandTextDisplay::operator==;
	using CommandTextDisplay::operator=;
	void	execute() override;
};

}

#endif // KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_NEWLINE_HPP
