/**
 * @file memcpy.c
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stddef.h>

__attribute__((used))
void	*memcpy(void *dst, const void *src, size_t n) 
{
	size_t			i;
	unsigned char	*buf1;
	unsigned char	*buf2;

	i = 0;
	buf1 = (unsigned char *)dst;
	buf2 = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		buf1[i] = buf2[i];
		i++;
	}
	return (buf1);
}
