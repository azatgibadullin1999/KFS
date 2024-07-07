/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.cc                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:03:28 by larlena           #+#    #+#             */
/*   Updated: 2024/07/06 16:51:51 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

void *operator new(size_t size) {
    return ::malloc(size);
}
 
void *operator new[](size_t size) {
    return ::malloc(size);
}
 
void operator delete(void *p) {
    ::free(p);
}
 
void operator delete[](void *p) {
    ::free(p);
}

inline void *operator new(size_t, void *p)     throw() { return p; }
inline void *operator new[](size_t, void *p)   throw() { return p; }
inline void  operator delete  (void *, void *) throw() { };
inline void  operator delete[](void *, void *) throw() { };

