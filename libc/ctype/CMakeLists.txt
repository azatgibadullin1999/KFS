add_library(kfs_libc_ctype
        isalnum.c
        isalpha.c
        isascii.c
        isdigit.c
        isprint.c
        isspace.c
        tolower.c
        toupper.c
)

add_library(kfs::libc::ctype
        ALIAS kfs_libc_ctype
)


