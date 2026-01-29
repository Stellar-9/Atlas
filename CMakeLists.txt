cmake_minimum_required(VERSION 3.28)

project(Atlas)

set(SOURCES
	src/main.cpp
	src/Lexer.cpp
)

add_executable(Atlas ${SOURCES})

target_include_directories(Atlas PRIVATE include)

target_compile_options(Atlas PRIVATE /std:c++17)