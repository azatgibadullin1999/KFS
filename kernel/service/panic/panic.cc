/**
 * @file panic.cc
 * @author larlena (azat251061@gmail.com)
 * @brief 
 * @version 0.1
 * @date 01-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <exception>

#include "panic.hpp"
#include "service/console/console.hpp"

const char*	g_panic_header_messege ="\
       )       (        )       (           (                 )  (          \n\
    ( /(       )\\ )  ( /(       )\\ )        )\\ )    (      ( /(  )\\ )   (   \n\
    )\\()) (   (()/(  )\\()) (   (()/(       (()/(    )\\     )\\())(()/(   )\\  \n\
   ((_)\\  )\\   /(_))((_)\\  )\\   /(_))       /(_))((((_)(  ((_)\\  /(_))(((_) \n\
   _ ((_)((_) (_))   _((_)((_) (_))        (_))   )\\ _ )\\  _((_)(_))  )\\___ \n\
  | |/ / | __|| _ \\ | \\| || __|| |         | _ \\  (_)_\\(_)| \\| ||_ _|((/ __|\n\
  | ' <  | _| |   / | .` || _| | |__       |  _/   / _ \\  | .` | | |  | (__ \n\
  |_|\\_\\ |___||_|_\\ |_|\\_||___||____|      |_|    /_/ \\_\\ |_|\\_||___|  \\___|\n";

[[noreturn]] void kfs::detail::panic() {
	auto&&	console = kfs::console::instance();
	auto&&  text_display = console.get_text_display();
	text_display->set_cursor_position(0, text_display->get_current_column());

	console.write(g_panic_header_messege);
	for (;;) { asm volatile ("hlt"); }
}

kfs::PanicHandler::PanicHandler() {
	std::set_terminate(kfs::detail::panic);
}
