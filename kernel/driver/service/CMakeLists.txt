add_library(kfs_driver_service
	command_default_auto_scroll.cc
	command_default.cc
	command_press_backspace.cc
	command_press_newline_auto_scroll.cc
	command_press_newline.cc
	command_press_scroll.cc
	command_press_tab.cc
)

target_include_directories(kfs_driver_service
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(kfs_driver_service
	PRIVATE kfs::common::pattern
	PRIVATE kfs::driver::common
)

add_library(kfs::driver::service
	ALIAS kfs_driver_service
)
