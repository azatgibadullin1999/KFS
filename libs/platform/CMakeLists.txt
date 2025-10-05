include_directories(SYSTEM
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(kfs_platform OBJECT
	src/sys/mmap.cc
	src/write.cc
	src/panic.cc
)

add_library(kfs::platform
	ALIAS kfs_platform
)

