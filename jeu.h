#ifndef PROJET_TAKUZU_JEU_H
#define PROJET_TAKUZU_JEU_H
#include "functions.h"
#include "indice.h"

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool grille_completee(char** grille);
void jouer(char** sol, char** masque, int vies);
int grille_correcte(char **grille);

#endif //PROJET_TAKUZU_JEU_H
