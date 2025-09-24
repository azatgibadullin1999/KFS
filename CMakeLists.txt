cmake_minimum_required(VERSION 3.22)
project(kfs
        VERSION 1.0.0
        LANGUAGES CXX C ASM-ATT)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


set(KFS_COMMON_FLAGS "-fno-builtin -fno-stack-protector -ffreestanding -Wconversion -Wall -Wextra -pedantic")
set(KFS_CXX_FLAGS "-fno-exceptions -std=c++23 -fno-rtti -fno-threadsafe-statics")
set(KFS_C_FLAGS "")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${KFS_COMMON_FLAGS} ${KFS_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${KFS_COMMON_FLAGS} ${KFS_CXX_FLAGS}")

include_directories(SYSTEM
	${CMAKE_CURRENT_SOURCE_DIR}/libcxx
	${CMAKE_CURRENT_SOURCE_DIR}/libc
	${CMAKE_CURRENT_SOURCE_DIR}/kernel
	${CMAKE_CURRENT_SOURCE_DIR}/kernel/api
	${CMAKE_CURRENT_SOURCE_DIR}/boot
)

execute_process(
	COMMAND ${CMAKE_C_COMPILER} -print-libgcc-file-name
	OUTPUT_VARIABLE LIBGCC_FILE
	OUTPUT_STRIP_TRAILING_WHITESPACE
)
add_subdirectory(kernel/api)
add_subdirectory(libc)
add_subdirectory(libcxx)
add_subdirectory(cxx-support)
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
