/**
 * @file command_default.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_COMMAND_DEFAULT_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_COMMAND_DEFAULT_HPP__

# include "command_text_display.hpp"

namespace kfs::driver::common {

class CommandDefault final : public kfs::interface::CommandTextDisplay<CommandDefault> {
public:
	using CommandTextDisplay::CommandTextDisplay;
	using CommandTextDisplay::operator=;
	void	execute() override;
};

}

#endif // __KFS_KERNEL_DRIVER_SERVICE_COMMAND_DEFAULT_HPP__