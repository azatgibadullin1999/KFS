add_library(kfs_service_shell OBJECT
	shell.cc
)

add_library(kfs::service::shell
	ALIAS kfs_service_shell
)
