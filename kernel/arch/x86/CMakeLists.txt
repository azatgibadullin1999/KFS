add_library(kfs_arch OBJECT
	hwio/port.cc
)

add_library(kfs::arch
	ALIAS kfs_arch
)
