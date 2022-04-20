#ifndef PROJET_TAKUZU_FUNCTIONS_H
#define PROJET_TAKUZU_FUNCTIONS_H
#include <stdlib.h>
#include <stdbool.h>

#define VIES 3

bool good_colonne(int**, int*, int);
bool good_ligne(int**, int*, int);
char** creer_masque(int);
void afficher_grille(int**, char**);
#endif //PROJET_TAKUZU_FUNCTIONS_H
