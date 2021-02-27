cmake_minimum_required(VERSION 3.17)
project(code)

set(CMAKE_CXX_STANDARD 17)

add_executable(code main.cpp Info.h xml/pugixml.cpp xml/pugixml.h xml/pugiconfig.h)