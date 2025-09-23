add_library(kfs_libc_errno OBJECT
        errno.c
)

add_library(kfs::libc::errno
        ALIAS kfs_libc_errno
)


