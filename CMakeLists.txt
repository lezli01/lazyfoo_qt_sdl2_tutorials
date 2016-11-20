cmake_minimum_required(VERSION 3.5.1)
project(fannis_main)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include(FindPkgConfig)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}$ "${CMAKE_SOURCE_DIR}/CMakeModules")

include(sdl)
include(qt)

add_subdirectory(src/tutorial_001)
