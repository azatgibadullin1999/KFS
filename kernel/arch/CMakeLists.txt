add_library(kfs_arch INTERFACE)

target_include_directories(kfs_arch INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(kfs::arch
	ALIAS kfs_arch
)
