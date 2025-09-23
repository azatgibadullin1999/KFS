add_library(kfs_driver_common OBJECT
	text_display.cc
)

add_library(kfs::driver::common
	ALIAS kfs_driver_common
)
