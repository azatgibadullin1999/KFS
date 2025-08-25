add_library(kfs_libc_stdio STATIC
        printf.c
)

include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(kfs_libc_stdio
	kfs::libc::string
	kfs::libc::ctype
	kfs::libc::stdlib
        kfs::api
)

add_library(kfs::libc::stdio
        ALIAS kfs_libc_stdio
)


