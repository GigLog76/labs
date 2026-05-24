add_library(task2_lib STATIC 
    HashTable.cpp
    task2.cpp
)
target_include_directories(task2_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(task1_lib PROPERTIES CXX_STANDARD 17)