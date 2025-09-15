/**
 * @file mbstate_t.h
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 14-09-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_LIBC_MBSTATE_T_H__
# define __KFS_LIBC_MBSTATE_T_H__

typedef struct {
  unsigned char __seq[4];
} mbstate_t;

#endif // __KFS_LIBC_MBSTATE_T_H__