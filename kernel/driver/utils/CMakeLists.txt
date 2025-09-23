add_library(kfs_driver_utils OBJECT
	port.cc
)

add_library(kfs::driver::utils
	ALIAS kfs_driver_utils
)
