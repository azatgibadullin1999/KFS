add_library(kfs_libc_stdlib STATIC
        malloc.c
        atoi.c
        itoa.c
)

include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(kfs_libc_stdlib
        kfs::libc::ctype
)

add_library(kfs::libc::stdlib
        ALIAS kfs_libc_stdlib
)


