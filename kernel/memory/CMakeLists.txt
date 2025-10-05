add_library(kfs_memory OBJECT
	memory.cc
	paging.cc
	gdt_default.cc
	address_space.cc
	physical_memory.cc
	imp/kernel_address_space.cc
)

add_library(kfs::memory
	ALIAS kfs_memory
)
