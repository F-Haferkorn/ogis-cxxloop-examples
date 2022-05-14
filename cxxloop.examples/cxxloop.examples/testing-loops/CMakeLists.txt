cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(THE_PROJECT cxxloop-testing-cxxloop2)

project(${THE_PROJECT} LANGUAGES CXX)


add_subdirectory(test_cxxloop_type_traits)
add_subdirectory(test_cxxloop_macros)
add_subdirectory(test_cxxloop_templates)

add_subdirectory(test_cxxloop)
add_subdirectory(test_cxxloop_typed)
#add_subdirectory(test_cxxloop3)
#POSTOPS
add_subdirectory(test_cxxloop_postops)
