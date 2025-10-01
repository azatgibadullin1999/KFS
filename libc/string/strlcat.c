/**
 * @file strlcat.c
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stddef.h>

size_t	strlen(const char *str);

size_t	strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	start;
	size_t	i;

	i = 0;
	start = strlen(dst);
	len = strlen(src) + start;
	if (start > dstsize)
		return (strlen(src) + dstsize);
	while (start + i < dstsize - 1 && src[i])
	{
		dst[start + i] = src[i];
		i++;
	}
	dst[start + i] = '\0';
	return (len);
}
