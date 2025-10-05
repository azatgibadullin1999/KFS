/**
 * @file strnstr.c
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stddef.h>

char	*strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str1[i] && i <= len)
	{
		j = 0;
		while (i < len && str1[i] && str2[j] && (str1[i] == str2[j]))
		{
			i++;
			j++;
		}
		if (str2[j] == '\0')
			return ((char *)&str1[i - j]);
		i = i - j;
		i++;
	}
	return (NULL);
}
