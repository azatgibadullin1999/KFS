/**
 * @file command_press_backspace.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_BACKSPACE_HPP
# define KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_BACKSPACE_HPP

# include <cstddef>
# include <kfs/command_text_display.hpp>

namespace kfs::driver::common {

class CommandPressBackspace final : public kfs::CommandTextDisplay<CommandPressBackspace> {
public:
	using CommandTextDisplay::CommandTextDisplay;
	using CommandTextDisplay::operator==;
	using CommandTextDisplay::operator=;
	void	execute() override;
};

}

#endif // KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_BACKSPACE_HPP
