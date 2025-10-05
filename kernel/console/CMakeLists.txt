add_library(kfs_console OBJECT
	console.cc
)

add_library(kfs::console
	ALIAS kfs_console
)
