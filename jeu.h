#ifndef PROJET_TAKUZU_JEU_H
#define PROJET_TAKUZU_JEU_H
#include "functions.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool grille_completee(char** masque);
void jouer(int** tab, char** masque, int vies);

#endif //PROJET_TAKUZU_JEU_H
