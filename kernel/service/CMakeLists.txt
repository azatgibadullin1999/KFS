add_subdirectory(console)
add_subdirectory(memory)
add_subdirectory(shell)
add_subdirectory(panic)

add_library(kfs_service INTERFACE)

target_link_libraries(kfs_service INTERFACE
	kfs::service::console
	kfs::service::shell
	kfs::service::memory
)

add_library(kfs::service
	ALIAS kfs_service
)
