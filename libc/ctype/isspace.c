/**
 * @file isspace.c
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <ctype.h>

int isspace(int c) {
	return (c == '\t' || c == '\v' || c == ' ' ||
		c == '\n' || c == '\r' || c == '\f');
}
