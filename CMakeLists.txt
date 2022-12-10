cmake_minimum_required(VERSION 3.16)

project(KyleBot)

set(BUILD_VOICE_SUPPORT OFF CACHE BOOL "")
set(RUN_LDCONFIG OFF CACHE BOOL "")
set(DPP_INSTALL OFF CACHE BOOL "")
set(DPP_BUILD_TEST OFF CACHE BOOL "")


add_subdirectory(lib/DPP)
add_subdirectory(lib/SQLiteCpp)


set(CMAKE_CXX_STANDARD 17)

include_directories(lib/DPP/include)
include_directories(lib/SQLiteCpp/include)

set(SRC_FILES src/main.cpp src/util.cpp src/util.h)


SET( CMAKE_EXPORT_COMPILE_COMMANDS ON )

IF( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json" )
  EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
  )
ENDIF()



add_executable(KyleBot ${SRC_FILES})

target_link_libraries(KyleBot dpp)
target_link_libraries(KyleBot SQLiteCpp)

set_target_properties(KyleBot PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

