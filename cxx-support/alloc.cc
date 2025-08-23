/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.cc                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:03:28 by larlena           #+#    #+#             */
/*   Updated: 2025/01/21 17:40:48 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

void *operator new(std::size_t size) {
    return ::malloc(size);
}
 
void *operator new[](std::size_t size) {
    return ::malloc(size);
}
 
void operator delete(void *p) {
    ::free(p);
}
 
void operator delete[](void *p) {
    ::free(p);
}

void operator delete(void* p, std::size_t sz [[maybe_unused]]) noexcept {
    ::free(p);
}

void operator delete[](void* p, std::size_t sz [[maybe_unused]]) noexcept {
    ::free(p);
}

inline void *operator new(size_t, void *p)     throw() { return p; }
inline void *operator new[](size_t, void *p)   throw() { return p; }
inline void  operator delete  (void *, void *) throw() { };
inline void  operator delete[](void *, void *) throw() { };

