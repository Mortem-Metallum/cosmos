cmake_minimum_required(VERSION 3.10)
project(CosmosPM C)


add_library(cosmos SHARED libcosmos.c)
set_target_properties(cosmos PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_executable(cosmos_c cosmos.c)
add_executable(comet_c comet.c)
target_link_libraries(cosmos_c PRIVATE cosmos)
target_link_libraries(comet_c PRIVATE cosmos)






