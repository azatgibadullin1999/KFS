/**
 * @file strlen.c
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stddef.h>

size_t	strlen(const char *str) {
	size_t i;

	for (i = 0; str[i] != '\0'; ++i) { }
	return i;
}
