cmake_minimum_required(VERSION 3.10)
project(MultiTask)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Подключаем подпроекты (каждый создаст свою статическую библиотеку)
add_subdirectory(task1)
add_subdirectory(task2)
add_subdirectory(task3)

# Создаём главную программу-переключатель
add_executable(main main.cpp)

# Линкуем библиотеки заданий
target_link_libraries(main
    PRIVATE
    task1_lib
    task2_lib
    task3_lib
)

# Добавляем корневую директорию для поиска заголовков (если они понадобятся)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})