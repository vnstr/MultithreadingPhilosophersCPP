cmake_minimum_required(VERSION 3.19)
project(MultithreadingPhilosophersCPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(simulation
        src/main.cpp
        src/config.cpp
        src/philosopher.cpp
        src/table.cpp
        src/timer.cpp
        src/utils.cpp)
target_include_directories(simulation PUBLIC include)
