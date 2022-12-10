cmake_minimum_required(VERSION 3.16)

project(KyleBot)

add_subdirectory(lib/DPP)


set(CMAKE_CXX_STANDARD 17)

include_directories(lib/DPP/include)

set(SRC_FILES src/main.cpp)


SET( CMAKE_EXPORT_COMPILE_COMMANDS ON )

IF( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/../compile_commands.json" )
  EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/../compile_commands.json
    ${CMAKE_CURRENT_SOURCE_DIR}/../compile_commands.json
  )
ENDIF()



add_executable(KyleBot ${SRC_FILES})

target_link_libraries(KyleBot dpp)

set_target_properties(KyleBot PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

