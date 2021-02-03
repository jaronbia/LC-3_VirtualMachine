cmake_minimum_required(VERSION 3.10)

# project name
project(lc3)

# include header files
include_directories(include)

# specify standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# get source files
file(GLOB SOURCES "src/*.cpp")

# add executable
add_executable(lc3 ${SOURCES})

