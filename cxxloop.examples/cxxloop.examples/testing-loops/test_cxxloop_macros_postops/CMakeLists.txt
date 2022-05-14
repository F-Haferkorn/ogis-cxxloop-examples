cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

set(THE_PROJECT cxxloop-testing-cxxloop-macros-postops)

project(${THE_PROJECT} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD             11)
set(CMAKE_CXX_STANDARD_REQUIRED    YES)

set(TEST_CXXLOOP    test_cxxloop_macros_postops.cpp    ../macro.h)

###############
add_executable(${THE_PROJECT}  ${TEST_CXXLOOP} )
target_link_libraries(${THE_PROJECT}  cxxloop )

target_include_directories(${THE_PROJECT}  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/.>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:.>
  $<INSTALL_INTERFACE:..>
)

