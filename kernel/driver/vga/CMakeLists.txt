add_library(kfs_driver_vga
	text_display.cc
)

target_include_directories(kfs_driver_vga
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(kfs_driver_vga
	PUBLIC kfs::driver::common
	PUBLIC kfs::driver::utils
)

add_library(kfs::driver::vga
	ALIAS kfs_driver_vga
)
