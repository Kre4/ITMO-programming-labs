cmake_minimum_required(VERSION 3.17)
project(code)

set(CMAKE_CXX_STANDARD 17)
include_directories(OpenGL)
include_directories(OpenGL/include) # OpenGL/include has to contain the required OpenGL's .h files
include_directories(OpenGL/lib) # OpenGL/lib has to contain the required OpenGL's .lib files
add_executable(code main.cpp cube.h side.h mini_cube.h rubik.h)