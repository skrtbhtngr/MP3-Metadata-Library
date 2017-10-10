cmake_minimum_required(VERSION 3.6)
project(lsmusic_1)

set(CMAKE_C_STANDARD 99)

file(GLOB SOURCE_FILES "src/*.c")
include_directories(include)
add_executable(lsmusic_1 ${SOURCE_FILES})