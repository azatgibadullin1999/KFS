/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.cc                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:03:28 by larlena           #+#    #+#             */
/*   Updated: 2025/09/19 19:03:15 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

void* operator new(std::size_t n)              noexcept {
	return std::malloc(n);
}
void* operator new[](std::size_t n)            noexcept {
	return std::malloc(n);
}

void  operator delete(void* p)                 noexcept {
	std::free(p);
}
void  operator delete[](void* p)               noexcept {
	std::free(p);
}
void  operator delete(void* p, std::size_t)    noexcept { }  // <- sized
void  operator delete[](void* p, std::size_t)  noexcept { }

void* operator new(std::size_t, void* p)       noexcept { }
void* operator new[](std::size_t, void* p)     noexcept { }
void  operator delete(void*, void*)            noexcept { }
void  operator delete[](void*, void*)          noexcept { }

