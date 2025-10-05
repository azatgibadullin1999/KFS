/**
 * @file isascii.c
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <ctype.h>

int isascii(int c) {
	return (c >= 0 && c <= 127);
}
