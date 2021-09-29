cmake_minimum_required(VERSION 3.20)
project(a_star)

set(CMAKE_CXX_STANDARD 14)

add_executable(a_star
        test.cpp
        objects.h
        api.h)
