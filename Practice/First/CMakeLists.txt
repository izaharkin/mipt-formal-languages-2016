cmake_minimum_required(VERSION 3.6)
project(First)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp LengthItem.cpp LengthItem.h Analyzer.cpp Analyzer.h RegexSolver.cpp RegexSolver.h)
add_executable(First ${SOURCE_FILES})