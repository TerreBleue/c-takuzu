#ifndef PROJET_TAKUZU_FUNCTIONS_H
#define PROJET_TAKUZU_FUNCTIONS_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 4

void pause();
int** static_to_dynamic(const int mat[SIZE][SIZE], int taille);
char** creer_masque(int taille);

void actualiser_grille_jeu(int** sol, char** masque, char** grille_jeu);

char** masque_manuel(int taille);
char** masque_aleatoire(int taille);
void afficher_grille(int** mat, char** masque);
void release_mat(int*** mat, int taille);

#endif //PROJET_TAKUZU_FUNCTIONS_H
