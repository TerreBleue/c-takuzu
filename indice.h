#ifndef PROJET_TAKUZU_INDICE_H
#define PROJET_TAKUZU_INDICE_H
#include "functions.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


int nombre_manquants(const char *str);
int donner_indice(char **mat, char **sol, int *i_res1, int *i_res2, char *nb_ind);
void afficher_indice(char** sol, int code, int i_res1, int i_res2, char nb_ind);

#endif //PROJET_TAKUZU_INDICE_H
