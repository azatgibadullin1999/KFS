/**
 * @file memcmp.c
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stddef.h>

int		memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*buf1;
	unsigned char	*buf2;

	i = 0;
	buf1 = (unsigned char *)s1;
	buf2 = (unsigned char *)s2;
	while (i < n)
	{
		if (buf1[i] - buf2[i] != 0)
			return (buf1[i] - buf2[i]);
		i++;
	}
	return (0);
}
