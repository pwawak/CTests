cmake_minimum_required(VERSION 3.12)
project(CTests C)

set(CMAKE_C_STANDARD 11)

add_executable(CTests
        test_5_11.c
        test_5_20.c
        test_6_11.c
        test_6_12.c
        test_6_15.c
        test_6_17.c
        test_7_28.c
        test_7_31.c
        test_7_8.c)
