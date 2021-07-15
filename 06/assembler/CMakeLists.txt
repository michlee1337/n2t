cmake_minimum_required(VERSION 3.20.5)

project(asm)

add_library(
    parser
    parser.h
    parser.cc
)

add_library(
    translator
    translator.h
    translator.cc
)

add_library(
    assembler
    assembler.h
    assembler.cc
)

add_executable(${PROJECT_NAME} main.cc)

target_link_libraries(asm PRIVATE parser)
target_link_libraries(asm PRIVATE translator)
target_link_libraries(asm PRIVATE assembler)