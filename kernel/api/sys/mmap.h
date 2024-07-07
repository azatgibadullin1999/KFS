/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:27:07 by larlena           #+#    #+#             */
/*   Updated: 2024/07/07 12:29:47 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __KFS_KERNEL_API_SYS_MMAP_H__
# define __KFS_KERNEL_API_SYS_MMAP_H__

# include <stddef.h>
# include <sys/types.h>

# define PROT_EXEC 0x0
# define PROT_READ 0x0
# define PROT_WRITE 0x0
# define PROT_NONE 0x0
# define MAP_PRIVATE 0x0
# define MAP_ANON 0x0

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);

int munmap(void *addr, size_t length);

int getpagesize(void);

#endif // __KFS_KERNEL_API_SYS_MMAP_H__
