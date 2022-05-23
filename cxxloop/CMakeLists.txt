cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(ogis-cpp-loop LANGUAGES  CXX)
set(CMAKE_CXX_STANDARD             11)
set(CMAKE_CXX_STANDARD_REQUIRED    YES)

if(MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

set(CPPLOOP_HDR
    include/cxxloop
    include/loop.h
    include/cxxloop.h
    include/cxxloop_postops.h
    include/cxxloop_prereqs.h

    #include/cxxloop_slice.h
    i#nclude/cxxloop_slice_postops.h
    include/cxxloop_slice_prereqs.h
    )

add_library(cxxloop   INTERFACE)
#target_sources(cxxloop  INTERFACE  ${CPPLOOP_HDR})

target_include_directories(cxxloop
  INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/include>
)
