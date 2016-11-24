cmake_minimum_required(VERSION 3.5.1)
project(fannis_main)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include(FindPkgConfig)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}$ "${CMAKE_SOURCE_DIR}/CMakeModules")

include(sdl)
include(qt)

include_directories(src/common)

add_subdirectory(src/common)
add_subdirectory(src/tutorial_001)
add_subdirectory(src/tutorial_002)
add_subdirectory(src/tutorial_003)
add_subdirectory(src/tutorial_004)
add_subdirectory(src/tutorial_005)
add_subdirectory(src/tutorial_006)
add_subdirectory(src/tutorial_007)
add_subdirectory(src/tutorial_008)
add_subdirectory(src/tutorial_009)
add_subdirectory(src/tutorial_010)
add_subdirectory(src/tutorial_011)
add_subdirectory(src/tutorial_012)
add_subdirectory(src/tutorial_013)
