/**
 * @file execption.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 21-09-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <array>
#include <cstddef>
#include <exception>
#include <kfs/panic.hpp>

extern "C" {

// void __cxa_throw(void* thrown_exception, void* type_info, void (*destructor)(void*)) {
// 	std::terminate();
// }
// void __cxa_rethrow() { }
// void* __cxa_allocate_exception(std::size_t size) {
// 	static std::array<std::byte, 0x1000> page;
// 	if (size > sizeof(page)) {
// 		std::terminate();
// 	}
// 	return page.data();
// }
// void __cxa_free_exception(void* ptr[[maybe_unused]]) { }
// void __cxa_begin_catch(void*) { }
void __cxa_end_catch() { }
void __gxx_personality_v0() { }

}
