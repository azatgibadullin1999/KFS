if (ENABLE_CLANG_TIDY)
	set(CLANG_TIDY_EXE
		clang-tidy
	)
	set(CLANG_TIDY_ARGS
		--quiet
		--config-file ${PROJECT_SOURCE_DIR}/.clang-tidy
		-extra-arg=--target=i386-elf
		-extra-arg=-U__linux__
		-extra-arg=-D__i386__
	)
	set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE};${CLANG_TIDY_ARGS}")
endif()

add_subdirectory(service)
add_subdirectory(driver)
add_subdirectory(common)

execute_process(
	COMMAND ${CMAKE_C_COMPILER} -print-libgcc-file-name
	OUTPUT_VARIABLE LIBGCC_FILE
	OUTPUT_STRIP_TRAILING_WHITESPACE
)

add_executable(${CMAKE_PROJECT_NAME}
	$<TARGET_OBJECTS:kfs::api>
	$<TARGET_OBJECTS:kfs::boot>
	$<TARGET_OBJECTS:kfs::libcxxabi>
	$<TARGET_OBJECTS:kfs::libc::stdio>
	$<TARGET_OBJECTS:kfs::libc::errno>
	$<TARGET_OBJECTS:kfs::libc::ctype>
	$<TARGET_OBJECTS:kfs::libc::string>
	$<TARGET_OBJECTS:kfs::libc::stdlib>
	$<TARGET_OBJECTS:kfs::driver::vga>
	$<TARGET_OBJECTS:kfs::driver::ps2>
	$<TARGET_OBJECTS:kfs::driver::utils>
	$<TARGET_OBJECTS:kfs::driver::common>
	$<TARGET_OBJECTS:kfs::driver::service>
	$<TARGET_OBJECTS:kfs::service::shell>
	$<TARGET_OBJECTS:kfs::service::panic>
	$<TARGET_OBJECTS:kfs::service::memory>
	$<TARGET_OBJECTS:kfs::service::console>
	kernel_main.cc
	kernel.cc
)

target_link_libraries(${CMAKE_PROJECT_NAME}
	${LIBGCC_FILE}
)

target_link_options(${CMAKE_PROJECT_NAME} PUBLIC
	-ffreestanding
	-nostartfiles
	-nostdlib
	-T "${CMAKE_CURRENT_SOURCE_DIR}/../boot/arch/i386/linker.ld"
)
