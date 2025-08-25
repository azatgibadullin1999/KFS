add_library(kfs_service_memory
	memory.cc
)

target_include_directories(kfs_service_memory
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(kfs_service_memory
	PUBLIC kfs::boot
)

add_library(kfs::service::memory
	ALIAS kfs_service_memory
)
