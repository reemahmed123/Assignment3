cmake_minimum_required(VERSION 3.27)
project(game)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(game
        main.cpp
        X_O_Board_App.cpp
        X_O_Board_App.h)
