/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_variable_support.cc                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:24:17 by larlena           #+#    #+#             */
/*   Updated: 2024/04/17 14:24:20 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *__dso_handle = 0;

extern "C" int __cxa_atexit(void (*destructor) (void *), void *arg, void *dso) {
	arg;
	dso;
	return 0;
}

extern "C" void __cxa_finalize(void *f) {
	f;
}
