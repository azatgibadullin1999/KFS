/**
 * @file errno.c
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 16-09-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

int *errno_location(void) {
	static int errno_val = 0;
	return &errno_val;
}
