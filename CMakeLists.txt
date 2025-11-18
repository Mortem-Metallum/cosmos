cmake_minimum_required(VERSION 3.10)
project(CosmosPM C)


add_library(libcosmos SHARED libcosmos.c)


add_executable(cosmos cosmos.c)
add_executable(comet comet.c)
target_link_libraries(cosmos PRIVATE libcosmos)
target_link_libraries(comet PRIVATE libcosmos)



