/**
 * @file command_press_tab.hpp
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_TAB_HPP__
# define __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_TAB_HPP__

# include <stdint.h>
# include <stddef.h>
# include "command_text_display.hpp"

namespace kfs::driver::common {

class CommandPressTab final : public kfs::interface::CommandTextDisplay<CommandPressTab> {
public:
	CommandPressTab(char c,kfs::driver::interface::ITextDisplay *textDisplay, size_t tabSize) :
	CommandTextDisplay(c, textDisplay),
	mTabSize(tabSize) { }
	using CommandTextDisplay::operator==;
	using CommandTextDisplay::operator=;

	void	execute() override;
private:
	size_t	mTabSize;
};

}

#endif // __KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_TAB_HPP__
