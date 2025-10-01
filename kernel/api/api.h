/**
 * @file api.h
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __KFS_KERNEL_API_API_HPP__
# define __KFS_KERNEL_API_API_HPP__

# include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void	__kfs_putchar(char c);
void	__kfs_puts(const char *str);
void	__kfs_panic();
void	*allocate_pages(size_t num_of_pages);

#ifdef __cplusplus
}
#endif

#endif // __KFS_KERNEL_API_API_HPP__
