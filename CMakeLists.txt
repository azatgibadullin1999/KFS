cmake_minimum_required(VERSION 3.22)
project(kfs
        VERSION 1.0.0
        LANGUAGES CXX C ASM-ATT)

option(ENABLE_CLANG_TIDY "Run clang-tidy during build" ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(KFS_COMMON_FLAGS
	-fno-builtin
	-fno-stack-protector
	-ffreestanding
	-Wall
	-Wextra
	-pedantic
)
set(KFS_CXX_FLAGS
	-fno-exceptions
	-std=c++23
	-fno-rtti
	-fno-threadsafe-statics
)
set(KFS_C_FLAGS)

string(JOIN " " KFS_COMMON_FLAGS_STR ${KFS_COMMON_FLAGS})
string(JOIN " " KFS_CXX_FLAGS_STR    ${KFS_CXX_FLAGS})
string(JOIN " " KFS_C_FLAGS_STR      ${KFS_C_FLAGS})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${KFS_COMMON_FLAGS_STR} ${KFS_C_FLAGS_STR}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${KFS_COMMON_FLAGS_STR} ${KFS_CXX_FLAGS_STR}")

include_directories(SYSTEM
	${CMAKE_CURRENT_SOURCE_DIR}/libs/libcxx/include
	${CMAKE_CURRENT_SOURCE_DIR}/libs/libc/include
	${CMAKE_CURRENT_SOURCE_DIR}/boot
)
include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/libs/patterns/include
	${CMAKE_CURRENT_SOURCE_DIR}/kernel/include
)

execute_process(
	COMMAND ${CMAKE_C_COMPILER} -print-libgcc-file-name
	OUTPUT_VARIABLE LIBGCC_FILE
	OUTPUT_STRIP_TRAILING_WHITESPACE
)
add_subdirectory(libs/platform/)
add_subdirectory(libs/libc)
add_subdirectory(libs/libcxxabi)
add_subdirectory(boot)
add_subdirectory(kernel)


set(KFS_ISO_TARGET "${CMAKE_PROJECT_NAME}.iso")
set(KFS_ISO_BUILD_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/root")


add_custom_target(iso ALL
        COMMAND grub-file --is-x86-multiboot $<TARGET_FILE:${CMAKE_PROJECT_NAME}>
	COMMAND mkdir -pv ${KFS_ISO_BUILD_DIRECTORY}/boot/grub
	COMMAND cp $<TARGET_FILE:${CMAKE_PROJECT_NAME}> ${KFS_ISO_BUILD_DIRECTORY}/boot
	COMMAND cp grub/grub.cfg ${KFS_ISO_BUILD_DIRECTORY}/boot/grub
	COMMAND grub-mkrescue -o ${CMAKE_CURRENT_BINARY_DIR}/${KFS_ISO_TARGET} ${KFS_ISO_BUILD_DIRECTORY}
        DEPENDS ${CMAKE_PROJECT_NAME}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(run
	COMMAND qemu-system-i386 -cdrom ${CMAKE_CURRENT_BINARY_DIR}/${KFS_ISO_TARGET}
        DEPENDS iso
)

add_custom_target(run_debug
	@qemu-system-i386 -kernel $<TARGET_FILE:${CMAKE_PROJECT_NAME}> -s -S -cdrom ${CMAKE_CURRENT_BINARY_DIR}/${KFS_ISO_TARGET}
        DEPENDS iso
)
