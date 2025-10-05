add_library(kfs_memory OBJECT
	memory.cc
	physical/physical_memory.cc
	virtual/paging.cc
	virtual/address_space.cc
	virtual/kernel_address_space.cc
	segmentation/gdt_default.cc
)

add_library(kfs::memory
	ALIAS kfs_memory
)
