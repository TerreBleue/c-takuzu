#ifndef PROJET_TAKUZU_INDICE_H
#define PROJET_TAKUZU_INDICE_H
#include "functions.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int code;
    int val_principale;
    int val_secondaire;
    char nombre_binaire;
} INDICE;

int nombre_manquants(const char *str);
void donner_indice(INDICE* indice, char **mat);
void afficher_indice(char** sol, INDICE indice);

#endif //PROJET_TAKUZU_INDICE_H
