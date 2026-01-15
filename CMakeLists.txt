cmake_minimum_required(VERSION 3.28)

project(Atlas)

add_executable(Atlas main.cpp Lexer.cpp)

target_compile_options(Atlas PRIVATE /std:c++17)