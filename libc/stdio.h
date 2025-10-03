/**
 * @file stdio.h
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef KFS_LIBC_STDIO_H
# define KFS_LIBC_STDIO_H

# ifdef __cplusplus
extern "C" {
# endif

#define EOF -1

int printf(const char *format, ...);
int putchar(char ch);
int puts(const char *ch);

# ifdef __cplusplus
}
# endif

#endif // KFS_LIBC_STDIO_H
