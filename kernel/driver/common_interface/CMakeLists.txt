add_library(kfs_driver_common
	text_display.cc
)

target_include_directories(kfs_driver_common
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(kfs_driver_common
	PUBLIC kfs::common::pattern
	PUBLIC kfs::driver::utils
)

add_library(kfs::driver::common
	ALIAS kfs_driver_common
)
