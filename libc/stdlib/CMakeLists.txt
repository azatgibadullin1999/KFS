add_library(kfs_libc_stdlib OBJECT
        abort.c
        malloc.c
        atoi.c
        itoa.c
        div.c
)

add_library(kfs::libc::stdlib
        ALIAS kfs_libc_stdlib
)


