cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

set(FILES
    ../asciiart.hpp
    asciishapes_using_loop.hpp
    asciishapes_using_loop.cpp
    main.cpp
    )

set(THE_PROJECT cxxloop-asciishapes-loop)

#set(CMAKE_CXX_STANDARD             11)
#set(CMAKE_CXX_STANDARD_REQUIRED    NO)

project(${THE_PROJECT} LANGUAGES CXX)

add_executable(  ${THE_PROJECT} ${FILES}  )

target_link_libraries(${THE_PROJECT}  cxxloop )
target_link_libraries(${THE_PROJECT}  cxxloop )
target_include_directories(${THE_PROJECT}  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/.>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:.>
  $<INSTALL_INTERFACE:..>
)

