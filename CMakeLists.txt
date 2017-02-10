cmake_minimum_required(VERSION 2.8)
project(cpsl)

find_package(BISON)
find_package(FLEX)

bison_target(CpslParser parser.y parser.cpp)
flex_target(CpslScanner scanner.l scanner.cpp)
add_flex_bison_dependency(CpslScanner CpslParser)

set(EXTRA_COMPILE_FLAGS "-g -std=c++0x")
#set(LCOV_FLAGS "--coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${EXTRA_COMPILE_FLAGS} ${LCOV_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LCOV_FLAGS}")

#set(main_srcs main.cpp)

#add_executable(cpsl ${main_srcs})
