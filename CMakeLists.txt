cmake_minimum_required(VERSION 3.5)
project(cpp_dev)

set(CMAKE_CXX_STANDARD 11)
# 设置自定义的cmakeModule， cmake优先从当前目录寻找依赖
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)

# 查找gflags包，设置头文件
find_package(GFLAGS REQUIRED)
include_directories(${GFLAGS_INCLUDE_DIR})
set(LIBS ${GFLAGS_LIBRARIES})

# 2. 添加头文件搜索路径
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/spdlog/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# 扫描目录下所有的代码，一会加入编译可执行程序中
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")

#message(STATUS "GLOB_RECURSE 找到 ${SOURCES} 个文件")
# 创建可执行程序
add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${LIBS})

# final 创建可以执行文件，这种是明确指向代码用来编译
#add_executable(${PROJECT_NAME} main.cpp
#        src/zlogger/zlogger.cpp
#        src/zlogger/zlogger.h
#        src/conf/flags.cpp
#        src/conf/flags.h
#)