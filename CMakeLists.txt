cmake_minimum_required(VERSION 3.22)

project(ICPC-Management-System)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CMAKE_BUILD_TYPE DEBUG)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(src)

add_definitions("-Wall -g -rdynamic")