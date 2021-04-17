cmake_minimum_required(VERSION 3.19)
project(MultithreadingPhilosophersCPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
        src/main.cpp
        src/config.cpp
        src/fork.cpp
        src/philosopher.cpp
        src/table.cpp
        src/timer.cpp
        src/utils.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)