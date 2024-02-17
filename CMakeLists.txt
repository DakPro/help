cmake_minimum_required(VERSION 3.26)
project(help C)

set(CMAKE_C_STANDARD 11)

add_executable(help
        debug.c
        src/mx_strlen.c
        src/mx_printint.c
        src/mx_printstr.c
        src/mx_printchar.c
)
