add_library(kfs_driver_utils
	port.cc
)

target_include_directories(kfs_driver_utils
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(kfs::driver::utils
	ALIAS kfs_driver_utils
)
