cmake_minimum_required(VERSION 3.10.0)
project(multifile)
set(SOURCE_FILES main.cpp Matrix.h Matrix.cpp Square_matrix.cpp Square_matrix.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES} )
