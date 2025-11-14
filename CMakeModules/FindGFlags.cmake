message(STATUS "start find gflags")

# 搜索头文件 给这个变量
find_path(GFLAGS_INCLUDE_DIR
        NAMES
        gflags/gflags.h
        HINTS
        /opt
        PATH_SUFFIXES
        include
)

# 搜索对应的so库
find_library(GFLAGS_LIBRARIES
        NAMES
        gflags
        HINTS
        /opt
        PATH_SUFFIXES
        lib
)

include(FindPackageHandleStandardArgs)

# 检查文件是否找到，如果没找到会报错
find_package_handle_standard_args(GFLAGS DEFAULT_MSG GFLAGS_INCLUDE_DIR GFLAGS_LIBRARIES)

#将变量标记为高级
mark_as_advanced(GFLAGS_INCLUDE_DIR GFLAGS_LIBRARIES)

message(STATUS "find gflags status: ${GFLAGS_FOUND}")
message(STATUS "find gflags include dir: ${GFLAGS_INCLUDE_DIR}")
message(STATUS "find gflags lib dir: ${GFLAGS_LIBRARIES}")
