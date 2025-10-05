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

#ifndef KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_TAB_HPP
# define KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_TAB_HPP

# include <cstddef>

# include <kfs/command_text_display.hpp>

namespace kfs::driver::common {

class CommandPressTab final : public kfs::CommandTextDisplay<CommandPressTab> {
public:
	CommandPressTab(char c, kfs::ITextDisplay *text_display, size_t tab_size) :
	CommandTextDisplay(c, text_display),
	_tab_size(tab_size) { }
	using CommandTextDisplay::operator==;
	using CommandTextDisplay::operator=;

	void	execute() override;
private:
	size_t	_tab_size;
};

}

#endif // KFS_KERNEL_DRIVER_SERVICE_COMMAND_PRESS_TAB_HPP
