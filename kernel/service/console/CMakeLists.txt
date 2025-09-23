add_library(kfs_service_console OBJECT
	console.cc
)

add_library(kfs::service::console
	ALIAS kfs_service_console
)
