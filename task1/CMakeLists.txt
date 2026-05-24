add_library(task1_lib STATIC 
    ./voting.cpp
    ./task1.cpp
   ./ Hash.cpp   
)
target_include_directories(task1_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(task1_lib PROPERTIES CXX_STANDARD 17)