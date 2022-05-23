cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

set(THE_PROJECT cxxloop-alternative-view-iota)

project(${THE_PROJECT} LANGUAGES CXX)


set(CMAKE_CXX_STANDARD             11)
set(CMAKE_CXX_STANDARD_REQUIRED    YES)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# Input
set(MATRIX_HDR  matrix.hpp 			matrix_io.hpp)
set(MATRIX_SRC  example_matrix.cpp 	main_matrix.cpp )


add_executable(${THE_PROJECT}  ${MATRIX_HDR} ${MATRIX_SRC} )
target_link_libraries(${THE_PROJECT} cxxloop)

target_include_directories(${THE_PROJECT} PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/.>
  $<INSTALL_INTERFACE:.>
)


