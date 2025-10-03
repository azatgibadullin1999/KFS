/**
 * @file string.h
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef KFS_LIBC_STRING_H
# define KFS_LIBC_STRING_H

# include <stddef.h>

# ifdef __cplusplus
extern "C" {
# endif

void *memset(void *b, int c, size_t len);
void bzero(void *s, size_t n);
void *memcpy(void *dst, const void *src, size_t n);
void *memccpy(void *dst, const void *src, int c, size_t n);
void *memmove(void *dst, const void *src, size_t len);
int memcmp(const void *s1, const void *s2, size_t n);
size_t strlen(const char *s);
size_t strlcpy(char *dst, const char *src, size_t dstsize);
size_t strlcat(char *dst, const char *src, size_t dstsize);
char *strchr(const char *s, int c);
char *strrchr(const char *s, int c);
char *strnstr(const char *str1, const char *str2, size_t len);
int strncmp(const char *str1, const char *str2, size_t n);
void *memchr(const void *s, int c, size_t n);

# ifdef __cplusplus
}
# endif

#endif // KFS_LIBC_STRING_H