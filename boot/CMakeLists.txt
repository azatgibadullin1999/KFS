enable_language(ASM-ATT)

add_library(kfs_boot OBJECT
        arch/i386/boot.s
)

target_include_directories(kfs_boot
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(kfs::boot
        ALIAS kfs_boot
)


