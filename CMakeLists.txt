cmake_minimum_required(VERSION 3.21)
project(Projet_Takuzu C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Projet_Takuzu
        main.c functions.c functions.h menu.c menu.h)
