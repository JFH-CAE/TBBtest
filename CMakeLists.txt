#CMakeLists.txt
cmake_minimum_required(VERSION 4.1)

#指定编译器路径
set(CMAKE_C_COMPILER gcc) 
set(CMAKE_CXX_COMPILER g++)
#设置C++标准
set(CMAKE_CXX_SCAN_FOR_MODULES ON) ##使用模块
##使用std模块
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")
set(CMAKE_CXX_STANDARD 23)
#设置项目名
project(MyProject LANGUAGES CXX)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# 启用调试符号
set(CMAKE_BUILD_TYPE Debug)
#设置编译器参数
if(CMAKE_BUILD_TYPE MATCHES "Debug")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")
elseif(CMAKE_BUILD_TYPE MATCHES "Release")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()

# 启用C++20模块支持
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmodules")
endif()

find_package(TBB)

add_library(TBB_module) #添加模块
target_sources(TBB_module
    PUBLIC
        FILE_SET CXX_MODULES FILES
        TBBModule.cppm #模块接口文件
    PRIVATE
    TBBModule.cpp
)
set(CMAKE_CXX_MODULE_STD 1)
add_executable(app main.cpp
                #TBB.cpp #测试模块时请注释掉
            )

#添加依赖关系
target_link_libraries(TBB_module TBB::tbb)
target_link_libraries(app TBB_module  
                #TBB::tbb #测试模块时请注释掉
                    )
