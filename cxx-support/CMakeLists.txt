add_library(kfs_cxx_support
        alloc.cc
        global_variable_support.cc
        pure_virtual_functions.cc
)

add_library(kfs::cxx::support
        ALIAS kfs_cxx_support
)

set(KFS_CXX_SUPPORT alloc.cc global_variable_support.cc pure_virtual_functions.cc)


