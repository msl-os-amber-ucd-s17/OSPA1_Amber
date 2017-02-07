cmake_minimum_required(VERSION 3.6)
project(OSPA1_Amber)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c tree.c tree.h)
add_executable(OSPA1_Amber ${SOURCE_FILES})