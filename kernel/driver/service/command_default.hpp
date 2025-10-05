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

#ifndef KFS_KERNEL_DRIVER_SERVICE_COMMAND_DEFAULT_HPP
# define KFS_KERNEL_DRIVER_SERVICE_COMMAND_DEFAULT_HPP

# include <kfs/command_text_display.hpp>

namespace kfs::driver::common {

class CommandDefault final : public kfs::CommandTextDisplay<CommandDefault> {
public:
	using CommandTextDisplay::CommandTextDisplay;
	using CommandTextDisplay::operator=;
	void	execute() override;
};

}

#endif // KFS_KERNEL_DRIVER_SERVICE_COMMAND_DEFAULT_HPP