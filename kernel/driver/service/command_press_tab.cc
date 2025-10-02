/**
 * @file command_press_tab.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "command_press_tab.hpp"

namespace kfs::driver::common {

void	CommandPressTab::execute() {
	auto&&	row = _text_display->get_current_row();
	auto&&	new_cursor_position = row + (_tab_size - (row % _tab_size));

	_text_display->set_cursor_position(new_cursor_position, _text_display->get_current_column());
}

}
