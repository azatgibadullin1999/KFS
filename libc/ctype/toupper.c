/**
 * @file toupper.c
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <ctype.h>

int toupper(int c) {
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
