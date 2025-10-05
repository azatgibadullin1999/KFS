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

#ifndef KFS_LIBS_LIBC_BITS_TYPES_MBSTATE_T_H
# define KFS_LIBS_LIBC_BITS_TYPES_MBSTATE_T_H

typedef struct {
  unsigned char __seq[4];
} mbstate_t;

#endif // KFS_LIBS_LIBC_BITS_TYPES_MBSTATE_T_H