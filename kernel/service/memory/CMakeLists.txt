add_library(kfs_service_memory
	memory.cc
	physical_memory.cc
	imp/init_x86.cc
)

target_include_directories(kfs_service_memory
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(kfs_service_memory
	PUBLIC kfs::boot
	PUBLIC kfs::arch
	PUBLIC kfs::common::pattern
)

add_library(kfs::service::memory
	ALIAS kfs_service_memory
)
