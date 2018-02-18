cmake_minimum_required(VERSION 3.10)

project(Hamming)
set(SOURCE Hamming.hpp)
set(TESTSOURCE test.cpp)
set(COMPILEROPTIONS -std=c++11 -Wall -pedantic)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCE} ${TESTSOURCE})
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE ${COMPILEROPTIONS})