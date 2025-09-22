add_library(kfs_libc_errno STATIC
        errno.c
)

add_library(kfs::libc::errno
        ALIAS kfs_libc_errno
)


