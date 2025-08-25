add_library(kfs_service_shell
	shell.cc
)

target_include_directories(kfs_service_shell
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(kfs_service_shell
	PUBLIC kfs::service::console
)

add_library(kfs::service::shell
	ALIAS kfs_service_shell
)
