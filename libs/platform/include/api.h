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

#ifndef KFS_LIBS_PLATFORM_HPP
# define KFS_LIBS_PLATFORM_HPP

# ifdef __cplusplus
#  include <cstddef>
# else
#  include <stddef.h>
# endif

# ifdef __cplusplus
extern "C" {
# endif

void	kfs_putchar(char c);
void	kfs_puts(const char *str);
void	kfs_panic();
void	*allocate_pages(size_t num_of_pages);

# ifdef __cplusplus
}
# endif

#endif // KFS_LIBS_PLATFORM_HPP
