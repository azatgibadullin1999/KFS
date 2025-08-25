add_library(kfs_service_console
	console.cc
)

target_include_directories(kfs_service_console
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(kfs_service_console
	PUBLIC kfs::driver::common
	PUBLIC kfs::common::pattern
)

add_library(kfs::service::console
	ALIAS kfs_service_console
)
