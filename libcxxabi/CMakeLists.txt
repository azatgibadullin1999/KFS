add_library(kfs_libcxxabi OBJECT
        alloc.cc
        execption.cc
        cxa_terminate.cc
        global_variable_support.cc
        pure_virtual_functions.cc
)

add_library(kfs::libcxxabi
        ALIAS kfs_libcxxabi
)
