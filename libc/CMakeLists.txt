include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/../kernel/api)
add_subdirectory(errno)
add_subdirectory(stdio)
add_subdirectory(stdlib)
add_subdirectory(string)
add_subdirectory(ctype)

add_library(kfs_libc OBJECT
	$<TARGET_OBJECTS:kfs::libc::errno>
	$<TARGET_OBJECTS:kfs::libc::string>
	$<TARGET_OBJECTS:kfs::libc::ctype>
	$<TARGET_OBJECTS:kfs::libc::stdlib>
	$<TARGET_OBJECTS:kfs::libc::stdio>
)

add_library(kfs::libc
        ALIAS kfs_libc
)
