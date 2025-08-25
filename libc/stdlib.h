/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:58:13 by larlena           #+#    #+#             */
/*   Updated: 2025/09/13 17:51:54 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDLIB_H
# define STDLIB_H

# include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void	*malloc(size_t);
void	free(void *);

#ifdef __cplusplus
}
#endif

#endif // STDLIB_H