add_library(kfs_shell OBJECT
	shell.cc
)

add_library(kfs::shell
	ALIAS kfs_shell
)
