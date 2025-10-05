add_subdirectory(common_interface)
add_subdirectory(ps2)
add_subdirectory(vga)
add_subdirectory(service)

add_library(kfs_driver INTERFACE)

target_link_libraries(kfs_driver INTERFACE
	kfs::driver::common
	kfs::driver::ps2
	kfs::driver::service
	kfs::driver::utils
	kfs::driver::vga
)

target_include_directories(kfs_driver INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(kfs::driver
	ALIAS kfs_driver
)
