cmake_minimum_required(VERSION 3.27)

project(RaylibTrial)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")

file (GLOB RaylibTrial_SRC
    "core/*.h"
    "core/*.hpp"
    "core/*.cpp"
    "core/*.c"
)

add_executable(RaylibTrial ${RaylibTrial_SRC})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(raylib REQUIRED)

find_library(raylib_LIBRARY raylib "C:/Program Files (x86)/raylib/lib")

set(FLECS_LIBRARY "C:/Program Files (x86)/flecs/lib/flecs_static.lib")
set(FLECS_INCLUDE_DIR "C:/Program Files (x86)/flecs/include")

set(raylib_INCLUDE_DIR "C:/Program Files (x86)/raylib/include")

target_include_directories(RaylibTrial
    PUBLIC ${FLECS_INCLUDE_DIR}
    PUBLIC ${raylib_INCLUDE_DIR}
)

target_link_libraries(RaylibTrial PUBLIC ${FLECS_LIBRARY} ${raylib_LIBRARY})
