/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.cc                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:03:28 by larlena           #+#    #+#             */
/*   Updated: 2025/09/24 21:50:11 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

