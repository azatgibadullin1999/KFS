/**
 * @file memmove.c
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stddef.h>

void	*memcpy(void *dst, const void *src, size_t n);

__attribute__((used))
void	*memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*buf1;
	unsigned char	*buf2;

	buf1 = (unsigned char *)dst;
	buf2 = (unsigned char *)src;
	if (len == 0)
		return (dst);
	if (src > dst)
		memcpy(dst, src, len);
	if (src < dst)
	{
		len--;
		while (len > 0)
		{
			buf1[len] = buf2[len];
			len--;
		}
		buf1[len] = buf2[len];
	}
	return (dst);
}
