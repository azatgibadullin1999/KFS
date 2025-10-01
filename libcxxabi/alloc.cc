/**
 * @file alloc.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <cstdlib>
#include <exception>

// scalar new
void* operator new(std::size_t n) {
	if (void* p = std::malloc(n))
		return p;
	std::terminate();
}
void* operator new(std::size_t n, std::align_val_t) {
	if (void* p = std::malloc(n))
		return p;
	std::terminate();
}

// array new
void* operator new[](std::size_t n) { return ::operator new(n); }
void* operator new[](std::size_t n, std::align_val_t a) { return ::operator new(n, a); }

// delete (unsized/sized, unaligned/aligned) — all forward to kfree
void operator delete(void* p) noexcept { free(p); }
void operator delete(void* p, std::size_t) noexcept { free(p); }
void operator delete(void* p, std::align_val_t) noexcept { free(p); }
void operator delete(void* p, std::size_t, std::align_val_t) noexcept { free(p); }

// arrays
void operator delete[](void* p) noexcept { ::operator delete(p); }
void operator delete[](void* p, std::size_t n) noexcept { ::operator delete(p, n); }
void operator delete[](void* p, std::align_val_t a) noexcept { ::operator delete(p, a); }
void operator delete[](void* p, std::size_t n, std::align_val_t a) noexcept { ::operator delete(p, n, a); }

