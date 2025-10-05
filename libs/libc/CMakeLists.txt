include_directories(SYSTEM
        ${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/../platform/include
)

add_library(kfs_libc OBJECT
        src/errno/errno.c
	src/string/bzero.c
        src/string/memchr.c
        src/string/memcmp.c
        src/string/memcpy.c
        src/string/memset.c
        src/string/strchr.c
        src/string/strlen.c
        src/string/memccpy.c
        src/string/memmove.c
        src/string/strlcat.c
        src/string/strlcpy.c
        src/string/strncmp.c
        src/string/strnstr.c
        src/string/strrchr.c
	src/ctype/isalnum.c
        src/ctype/isalpha.c
        src/ctype/isascii.c
        src/ctype/isdigit.c
        src/ctype/isprint.c
        src/ctype/isspace.c
        src/ctype/tolower.c
        src/ctype/toupper.c
	src/stdlib/abort.c
        src/stdlib/malloc.c
        src/stdlib/atoi.c
        src/stdlib/itoa.c
        src/stdlib/div.c
	src/stdio/printf.c
	src/stdio/putchar.c
	src/stdio/puts.c
)

add_library(kfs::libc
        ALIAS kfs_libc
)
