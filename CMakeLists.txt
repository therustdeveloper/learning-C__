cmake_minimum_required(VERSION 3.29)
project(learning_c__)

set(CMAKE_CXX_STANDARD 20)

add_executable(learning_c__ main.cpp
        variables/variables.cpp
        variables/variables.h
        functions/overloading.cpp
        functions/overloading.h)
