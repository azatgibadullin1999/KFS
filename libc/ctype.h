/**
 * @file ctype.h
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_LIBC_CTYPE_H__
# define __KFS_LIBC_CTYPE_H__

# ifdef __cplusplus
extern "C" {
# endif

int isalpha(int c);
int isdigit(int c);
int isalnum(int c);
int isascii(int c);
int isprint(int c);
int isspace(int c);
int toupper(int c);
int tolower(int c);

# ifdef __cplusplus
}
# endif

#endif // __KFS_LIBC_CTYPE_H__