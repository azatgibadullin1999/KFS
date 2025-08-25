add_library(kfs_api
	# sys/mmap.cc
	write.cc
)

include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(kfs_api
	PUBLIC kfs::service
)

add_library(kfs::api
	ALIAS kfs_api
)

