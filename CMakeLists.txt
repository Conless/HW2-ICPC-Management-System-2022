cmake_minimum_required(VERSION 3.22)
project(ICPC-Management-System)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}   -Ofast")

include_directories(
    ${PROJECT_SOURCE_DIR}/include/
    ${PROJECT_SOURCE_DIR}/src/
)
set(src_dir
    ${PROJECT_SOURCE_DIR}/src/main.cpp
    ${PROJECT_SOURCE_DIR}/src/ICPC.cc
    ${PROJECT_SOURCE_DIR}/src/data.cc
)
file(GLOB icpc-src
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

add_library(icpc-runtime ${icpc-src})
add_executable(ICPC ${src_dir} src/main.cpp)
target_link_libraries(ICPC icpc-runtime)
