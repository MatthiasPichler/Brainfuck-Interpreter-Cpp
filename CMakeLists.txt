cmake_minimum_required(VERSION 3.7)
project(Brainfuck_Interpreter_Cpp)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Interpreter.cpp Interpreter.hpp)
add_executable(Brainfuck_Interpreter_Cpp ${SOURCE_FILES})