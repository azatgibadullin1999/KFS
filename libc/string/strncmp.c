/**
 * @file strncmp.c
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stddef.h>

int		strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*buf1;
	unsigned char	*buf2;
	size_t			i;

	i = 0;
	buf1 = (unsigned char *)str1;
	buf2 = (unsigned char *)str2;
	while (i < n && buf1[i] && buf2[i])
	{
		if (buf1[i] - buf2[i] != 0)
			return (buf1[i] - buf2[i]);
		i++;
	}
	if ((buf1[i] == '\0' || buf2[i] == '\0') && i != n)
		return (buf1[i] - buf2[i]);
	return (0);
}
