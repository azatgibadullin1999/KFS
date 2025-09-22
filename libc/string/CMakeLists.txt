add_library(kfs_libc_string
        bzero.c
        memchr.c
        memcmp.c
        memcpy.c
        memset.c
        strchr.c
        strlen.c
        memccpy.c
        memmove.c
        strlcat.c
        strlcpy.c
        strncmp.c
        strnstr.c
        strrchr.c
)

add_library(kfs::libc::string
        ALIAS kfs_libc_string
)


