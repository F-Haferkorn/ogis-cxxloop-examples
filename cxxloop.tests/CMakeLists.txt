cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(cxxloop.test LANGUAGES CXX)

set(CMAKE_CXX_STANDARD             11)
set(CMAKE_CXX_STANDARD_REQUIRED    YES)

add_subdirectory(testing-loops)
