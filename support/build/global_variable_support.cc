/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_variable_support.cc                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:24:17 by larlena           #+#    #+#             */
/*   Updated: 2024/05/21 16:21:23 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *__dso_handle = 0;

extern "C" int __cxa_atexit(void (*destructor [[maybe_unused]]) (void *), void *arg [[maybe_unused]], void *dso [[maybe_unused]]) {
	return 0;
}

extern "C" void __cxa_finalize(void *f [[maybe_unused]]) {
}
