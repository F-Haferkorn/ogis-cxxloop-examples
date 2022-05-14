cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(ogis-godbolt.examples)


add_executable(ogis-loop-godbolt-example
    ogis-loop-godbolt-example.cpp)

link_libraries(ogis-loop-godbolt-example cxxloop)
