cmake_minimum_required(VERSION 3.10)
project(CosmosPM C)

add_compile_options("-v")
add_executable(cosmos cosmos.c)
add_executable(comet comet.c)
