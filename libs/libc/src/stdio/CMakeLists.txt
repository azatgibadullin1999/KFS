add_library(kfs_libc_stdio OBJECT
        printf.c
	putchar.c
	puts.c
)

add_library(kfs::libc::stdio
        ALIAS kfs_libc_stdio
)


