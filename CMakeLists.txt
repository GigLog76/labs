cmake_minimum_required(VERSION 3.10.0)
project(multifile)
set(SOURCE_FILES main.cpp long.h task3.cpp task2.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} )

