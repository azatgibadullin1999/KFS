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

#include <cstddef>

namespace {

void inline __kfs_halt() {
	asm volatile (
	"hlt"
	);
}

}

extern "C" {

void __cxa_throw(void* thrown_exception, void* type_info, void (*destructor)(void*)) { __kfs_halt();}
void __cxa_rethrow() { __kfs_halt();}
void* __cxa_allocate_exception(std::size_t size) { __kfs_halt(); return nullptr; }
void __cxa_free_exception(void* ptr[[maybe_unused]]) { __kfs_halt();}
void __cxa_begin_catch(void*) { __kfs_halt(); }
void __cxa_end_catch() { __kfs_halt(); }
void __gxx_personality_v0() { __kfs_halt();}

}
