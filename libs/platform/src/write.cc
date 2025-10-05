/**
 * @file write.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

# include "../console/console.hpp"

extern "C" {

void	kfs_putchar(char c) {
	kfs::console::instance().write(c);
}

void	kfs_puts(const char *str) {
	kfs::console::instance().write(str);
}

}
