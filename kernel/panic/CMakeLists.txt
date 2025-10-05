add_library(kfs_panic OBJECT
	panic.cc
)

add_library(kfs::panic
	ALIAS kfs_panic
)
