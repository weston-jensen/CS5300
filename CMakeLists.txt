cmake_minimum_required(VERSION 2.8)
project(cpsl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(BISON)
find_package(FLEX)

flex_target(scanner scanner.lex ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp)
bison_target(parser parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp
        COMPILE_FLAGS "-d  -v --report-file=${CMAKE_CURRENT_BINARY_DIR}/bison.output")

set(COMMON_SOURCES
    Array_Type.hpp
    Array_Type.cpp
    Constant.hpp
    Constant.cpp
    Expressions.cpp
    Expressions.hpp
    Record.hpp
    Record.cpp
    Symbol.hpp
    symbol_table.cpp
    symbol_table.hpp
    TreeParser.cpp
    TreeParser.hpp
    Type.hpp
    Type.cpp
    Var.hpp
    Var.cpp)

set(COMPILER_SOURCES
    main.cpp
    scanner
    parser)

include_directories(
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(cpsl ${COMMON_SOURCES} ${COMPILER_SOURCES})
