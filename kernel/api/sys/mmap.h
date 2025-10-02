/**
 * @file mmap.h
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_API_SYS_MMAP_H__
# define __KFS_KERNEL_API_SYS_MMAP_H__

# ifdef __cplusplus
#  include <cstddef>
# else
#  include <stddef.h>
# endif

# include <sys/types.h>

# ifdef __cplusplus
extern "C" {
# endif

# define PROT_EXEC 0x0
# define PROT_READ 0x0
# define PROT_WRITE 0x0
# define PROT_NONE 0x0
# define MAP_PRIVATE 0x0
# define MAP_ANON 0x0

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);

int munmap(void *addr, size_t length);

int getpagesize(void);

# ifdef __cplusplus
}
# endif

#endif // __KFS_KERNEL_API_SYS_MMAP_H__
