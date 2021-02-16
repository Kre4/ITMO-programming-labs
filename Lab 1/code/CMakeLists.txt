cmake_minimum_required(VERSION 3.17)
project(code)

set(CMAKE_CXX_STANDARD 20)

add_executable(code main.cpp geometry/point.h geometry/BrokenLine.h geometry/Chain.h geometry/Polygon.h geometry/Triangle.h)