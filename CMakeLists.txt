cmake_minimum_required(VERSION 3.10)

project(JavaCompiler)

set (SOURCE_FILES
  main.cpp
  lexer/lexer.cpp
  token/token.cpp)

add_executable(JavaCompiler ${SOURCE_FILES})