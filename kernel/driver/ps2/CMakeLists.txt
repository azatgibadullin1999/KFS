add_library(kfs_driver_ps2 OBJECT
	keyboard.cc
)

add_library(kfs::driver::ps2
	ALIAS kfs_driver_ps2
)
