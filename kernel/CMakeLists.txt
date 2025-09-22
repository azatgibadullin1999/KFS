add_subdirectory(service)
add_subdirectory(driver)
add_subdirectory(common)
add_subdirectory(arch)

execute_process(
	COMMAND ${CMAKE_C_COMPILER} -print-libgcc-file-name
	OUTPUT_VARIABLE LIBGCC_FILE
	OUTPUT_STRIP_TRAILING_WHITESPACE
)

add_executable(${CMAKE_PROJECT_NAME}
	kernel_main.cc
	kernel.cc
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${CMAKE_PROJECT_NAME}
	kfs::boot
	kfs::driver::common
	kfs::driver::service
	kfs::driver::utils
	kfs::driver::vga
	kfs::service::console
	kfs::driver::ps2
	kfs::service::shell
	kfs::service::memory
)

target_link_options(${CMAKE_PROJECT_NAME} PUBLIC
	-ffreestanding
	-nostartfiles
	-nostdlib
	-T "${CMAKE_CURRENT_SOURCE_DIR}/../boot/arch/i386/linker.ld"
)
