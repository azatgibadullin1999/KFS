/**
 * @file putchar.c
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 22-09-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <api.h>

int putchar(int ch) {
	kfs_putchar((char)ch);
	return 1;
}
