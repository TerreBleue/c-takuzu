cmake_minimum_required(VERSION 3.21)
project(Projet_Takuzu C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Projet_Takuzu
        main.c fonctions.c fonctions.h menu.c menu.h jeu.c jeu.h resolution.c resolution.h indice.c indice.h masque.c masque.h generation.c generation.h)
