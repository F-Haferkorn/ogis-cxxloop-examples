cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

set(THE_PROJECT cxxloop-asciishapes-for)

#set(CMAKE_CXX_STANDARD             11)
#set(CMAKE_CXX_STANDARD_REQUIRED    NO)

project(${THE_PROJECT} LANGUAGES CXX)


set(FILES
    ../asciiart.hpp
    asciishapes_using_for.hpp
    asciishapes_using_for.cpp
    main.cpp
    )

add_executable(  ${THE_PROJECT} ${FILES}  )


target_link_libraries(${THE_PROJECT}  cxxloop )

target_include_directories(${THE_PROJECT}  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/.>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:.>
  $<INSTALL_INTERFACE:..>
)


