/**
 * @file memchr.c
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
void	*memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char	*buf;

	i = 0;
	buf = (unsigned const char *)s;
	while (i < n)
	{
		if (buf[i] == (unsigned char)c)
			return ((void *)&buf[i]);
		i++;
	}
	return (0);
}
