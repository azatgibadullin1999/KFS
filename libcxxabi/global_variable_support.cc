/**
 * @file global_variable_support.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

void *__dso_handle = 0;

extern "C" {

int __cxa_atexit(void (*destructor [[maybe_unused]]) (void *), void *arg [[maybe_unused]], void *dso [[maybe_unused]]) {
	return 0;
}

void __cxa_finalize(void *f [[maybe_unused]]) { }

}