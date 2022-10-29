# 设置工程名称
set(PROJECT_NAME ${CMAKE_PROJECT_NAME})

aux_source_directory (. SRC_LIST)

add_executable(${PROJECT_NAME}_run ${SRC_LIST} 
    ${Util_LIST} ${Log_LIST} 
    ${File_LIST} ${CMD_LIST} 
    ${Config_LIST} ${Thread_LIST}
    ${Poller_LIST}
)

add_library(${PROJECT_NAME}_lib STATIC ${SRC_LIST} 
    ${Util_LIST} ${Log_LIST} 
    ${File_LIST} ${CMD_LIST} 
    ${Config_LIST} ${Thread_LIST}
    ${Poller_LIST}
)

target_link_libraries (${PROJECT_NAME}_run pthread)
 
add_definitions("-Wall -g -rdynamic")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/out/bin)

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/out/lib)