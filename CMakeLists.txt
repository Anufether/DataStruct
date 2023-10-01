cmake_minimum_required(VERSION 3.16.3)
project(DataStruct C)

set(CMAKE_C_STANDARD 11)

# add_executable(linear_table linear_table/linear_table.c)
add_executable(linear_table linear_table/linear_table_main.c linear_table/linear_table.c)
target_include_directories(linear_table PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
add_executable(linked_list linear_table/linked_list_main.c linear_table/linked_list.c)
target_include_directories(linear_table PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})