# Licensed under Apache 2.0.
# Developed by Aquiles Trindade (trindadedev).

cmake_minimum_required(VERSION 3.10)

set(PROGRAM_NAME JavaCompiler)

set (SOURCE_FILES
  main.cpp
  lexer/lexer.cpp
  token/token.cpp)

project(${PROGRAM_NAME})

add_executable(${PROGRAM_NAME} ${SOURCE_FILES})