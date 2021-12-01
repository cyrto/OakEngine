cmake_minimum_required (VERSION 3.8)

project ("OakEngine")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/Source/cmake/")


add_subdirectory ("Editor")
add_subdirectory ("Engine")