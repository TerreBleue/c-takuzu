#ifndef PROJET_TAKUZU_FUNCTIONS_H
#define PROJET_TAKUZU_FUNCTIONS_H
#include <stdbool.h>
#include <stdlib.h>

#define VIES 3

int** static_to_dynamic(int** mat, int n);
char** creer_masque(int);
char** masque_manuel(int Taille);
char** masque_aleatoire(int taille);
void afficher_grille(int**, char**);
void release_mat(int** mat, int n);

#endif //PROJET_TAKUZU_FUNCTIONS_H
