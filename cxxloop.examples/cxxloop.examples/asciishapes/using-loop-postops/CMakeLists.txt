cmake_minimum_required(VERSION 3.18 FATAL_ERROR)


set(FILES
    ../asciiart.hpp
    asciishapes_using_loop_postops.hpp
    asciishapes_using_loop_postops.cpp
    main.cpp
    )

cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

set(THE_PROJECT cxxloop-examples-asciishapes-loop-postops)

#set(CMAKE_CXX_STANDARD             ${CXXLOOP_CXX_STANDARD})
#set(CMAKE_CXX_STANDARD_REQUIRED    ${CXXLOOP_CXX_STANDARD_REQUIRED})

project(${THE_PROJECT} LANGUAGES CXX)


add_executable(  ${THE_PROJECT} ${FILES}  )

target_link_libraries(${THE_PROJECT}  cxxloop )
target_include_directories(${THE_PROJECT}  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/.>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/...>
  $<INSTALL_INTERFACE:.>
  $<INSTALL_INTERFACE:..>
)
