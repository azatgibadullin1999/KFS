/**
 * @file errno.h
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 16-09-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_LIBC_ERRNO_H__
# define __KFS_LIBC_ERRNO_H__

# ifdef __cplusplus
extern "C" {
# endif

int *errno_location(void);
# define errno (*errno_location())

# ifdef __cplusplus
}
# endif

#endif // __KFS_LIBC_ERRNO_H__
