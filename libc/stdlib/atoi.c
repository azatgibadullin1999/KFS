/**
 * @file atoi.c
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <ctype.h>
#include <stddef.h>

int atoi(const char *str) {
	size_t		it = 0;
	int		sign = 1;
	long long	dst = 0;

	while (isspace(str[it]))
		it++;
	if (str[it] == '-' || str[it] == '+') {
		if (str[it] == '-')
			sign = -1;
		it++;
	}
	while (isdigit(str[it])) {
		dst = dst * 10 + str[it] - '0';
		it++;
	}
	return (dst * sign);
}
