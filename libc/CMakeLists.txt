add_subdirectory(stdio)
add_subdirectory(stdlib)
add_subdirectory(string)
add_subdirectory(ctype)

add_library(kfs_libc INTERFACE)

target_link_libraries(kfs_libc INTERFACE
	kfs::libc::stdlib
	kfs::libc::string
	kfs::libc::ctype
	kfs::libc::stdio
)

include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR})


add_library(kfs::libc
        ALIAS kfs_libc
)
