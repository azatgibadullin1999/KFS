add_library(kfs_driver_vga OBJECT
	text_display.cc
)

add_library(kfs::driver::vga
	ALIAS kfs_driver_vga
)
