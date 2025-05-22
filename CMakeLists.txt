cmake_minimum_required(VERSION 3.5)
project(SpecialDates C)

add_library(chisla SHARED 
    funcchisla.c 
)


set_target_properties(chisla PROPERTIES OUTPUT_NAME "chisla")

add_executable(lab rgrChisla.c)

target_link_libraries(lab chisla)