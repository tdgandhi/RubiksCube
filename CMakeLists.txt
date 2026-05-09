cmake_minimum_required(VERSION 3.20)
project(RubiksCube LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(rubiks rubiks.cc cube.cc face.cc)
target_include_directories(rubiks PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

if(NOT MSVC)
  target_compile_options(rubiks PRIVATE -Wall -Wextra -Wpedantic)
endif()
