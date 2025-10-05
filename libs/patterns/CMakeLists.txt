add_library(kfs_common_pattern INTERFACE)

target_include_directories(kfs_common_pattern INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(kfs::common::pattern
	ALIAS kfs_common_pattern
)