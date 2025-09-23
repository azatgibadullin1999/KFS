add_library(kfs_service_memory OBJECT
	memory.cc
	physical_memory.cc
	imp/init_x86.cc
)

add_library(kfs::service::memory
	ALIAS kfs_service_memory
)
