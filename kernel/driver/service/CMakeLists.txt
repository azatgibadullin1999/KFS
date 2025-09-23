add_library(kfs_driver_service OBJECT
	command_default_auto_scroll.cc
	command_default.cc
	command_press_backspace.cc
	command_press_newline_auto_scroll.cc
	command_press_newline.cc
	command_press_scroll.cc
	command_press_tab.cc
)

add_library(kfs::driver::service
	ALIAS kfs_driver_service
)
