/**
 * @file puts.c
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 22-09-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <api.h>
#include <string.h>

int puts(const char* str) {
	__kfs_puts(str);
	return strlen(str);
}
