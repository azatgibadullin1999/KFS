/**
 * @file memccpy.c
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stddef.h>

void	*memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*buf1;
	unsigned char	*buf2;

	i = 0;
	buf1 = (unsigned char *)dst;
	buf2 = (unsigned char *)src;
	while (i < n)
	{
		buf1[i] = buf2[i];
		if (buf2[i] == (unsigned char)c)
			return ((void *)&buf1[i + 1]);
		i++;
	}
	return (NULL);
}
