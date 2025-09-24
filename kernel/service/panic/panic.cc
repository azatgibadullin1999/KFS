/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.cc                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larlena <larlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:20:08 by larlena           #+#    #+#             */
/*   Updated: 2025/09/24 19:03:29 by larlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "panic.hpp"
#include "service/console/console.hpp"
#include <exception>

const char*	gPanicHeaderMessege ="\
       )       (        )       (           (                 )  (          \n\
    ( /(       )\\ )  ( /(       )\\ )        )\\ )    (      ( /(  )\\ )   (   \n\
    )\\()) (   (()/(  )\\()) (   (()/(       (()/(    )\\     )\\())(()/(   )\\  \n\
   ((_)\\  )\\   /(_))((_)\\  )\\   /(_))       /(_))((((_)(  ((_)\\  /(_))(((_) \n\
   _ ((_)((_) (_))   _((_)((_) (_))        (_))   )\\ _ )\\  _((_)(_))  )\\___ \n\
  | |/ / | __|| _ \\ | \\| || __|| |         | _ \\  (_)_\\(_)| \\| ||_ _|((/ __|\n\
  | ' <  | _| |   / | .` || _| | |__       |  _/   / _ \\  | .` | | |  | (__ \n\
  |_|\\_\\ |___||_|_\\ |_|\\_||___||____|      |_|    /_/ \\_\\ |_|\\_||___|  \\___|\n";

void kfs::detail::panic() {
	auto&&	console = kfs::console::instance();
	auto&&  text_display = console.getTextDisplay();
	text_display->setCursorPosition(0, text_display->getCurrentColumn());

	console.write(gPanicHeaderMessege);
	asm volatile (
	"hlt"
	);
}

kfs::PanicHandler::PanicHandler() {
	std::set_terminate(kfs::detail::panic);
}
