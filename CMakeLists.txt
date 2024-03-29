cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 17)
project(MathLib)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

if(UNIX)
    find_package(Threads)
    add_compile_options(-g)
endif()

## Enable Google test library
enable_testing()

## TODO activate testing flag on parameter
set(CMAKE_CXX_FLAGS "-W -Wall -fprofile-arcs -ftest-coverage")

set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Point2.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Point3.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Vector3.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Matrix.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/angle.cpp
)

## Compile math librairie
add_library(libmath STATIC
    ${SRC}
)

## General sources
target_sources(libmath INTERFACE
    ${SRC}
)

## Include headers to librairie
target_include_directories(libmath INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(libmath PROPERTIES LINKER_LANGUAGE CXX)

export(
    TARGETS libmath
    FILE BLibraryConfig.cmake
)

set(SRC_EXEC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

## Creating executable of test main
add_executable(mathlib_test
    ${SRC_EXEC}
)

target_link_libraries(mathlib_test libmath)

## Test sources
set (SRC_TEST
    tests/main.cpp
    tests/utils.cpp
    tests/test_vector.cpp
    tests/test_angle.cpp
    tests/test_matrix.cpp
)

## including google test library
include(GoogleTest)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../tests)

## Creating executable of unit tests
add_executable(unit_tests
    ${SRC_TEST}
)

target_include_directories(unit_tests PRIVATE
    tests/
)

## Linking libraries to street
target_link_libraries(unit_tests PUBLIC
    CONAN_PKG::gtest
    ${CMAKE_THREAD_LIBS_INIT}
    ${CMAKE_DL_LIBS}
    libmath
)