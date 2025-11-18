cmake_minimum_required(VERSION 3.10)
project(CosmosPM C)


add_library(cosmospm SHARED libcosmospm.c)
set_target_properties(cosmospm PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_executable(cosmos cosmos.c)
add_executable(comet comet.c)
target_link_libraries(cosmos PRIVATE cosmospm)
target_link_libraries(comet PRIVATE cosmospm)







