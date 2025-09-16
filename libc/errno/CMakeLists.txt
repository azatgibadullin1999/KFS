add_library(kfs_libc_errno STATIC
        errno.c
)

include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR})

add_library(kfs::libc::errno
        ALIAS kfs_libc_errno
)


