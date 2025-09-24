add_library(kfs_service_panic OBJECT
	panic.cc
)

add_library(kfs::service::panic
	ALIAS kfs_service_panic
)
