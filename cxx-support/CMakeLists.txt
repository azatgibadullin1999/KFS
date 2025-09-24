add_library(kfs_cxx_support OBJECT
        alloc.cc
        execption.cc
        cxa_terminate.cc
        global_variable_support.cc
        pure_virtual_functions.cc
)

add_library(kfs::cxx::support
        ALIAS kfs_cxx_support
)
