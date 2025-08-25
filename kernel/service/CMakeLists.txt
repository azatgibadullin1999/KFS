add_subdirectory(console)
add_subdirectory(memory)
add_subdirectory(shell)

add_library(kfs_service INTERFACE)

target_link_libraries(kfs_service INTERFACE
	kfs::service::console
	kfs::service::shell
	kfs::service::memory
)

target_include_directories(kfs_service INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(kfs::service
	ALIAS kfs_service
)
