add_library(kfs_driver_ps2
	keyboard.cc
)

target_include_directories(kfs_driver_ps2
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(kfs_driver_ps2
	PUBLIC kfs::driver::common
	PUBLIC kfs::driver::utils
)

add_library(kfs::driver::ps2
	ALIAS kfs_driver_ps2
)
