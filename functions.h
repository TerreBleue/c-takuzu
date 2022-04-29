#ifndef PROJET_TAKUZU_FUNCTIONS_H
#define PROJET_TAKUZU_FUNCTIONS_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 4
#define VIES 3


void pause();
char** static_to_dynamic(int taille);
char** creer_masque(int taille);
void actualiser_grille_jeu(char** sol, char** masque, char** grille_jeu);
void afficher_grille(char** grille);
char** masque_manuel(int taille);
char** masque_aleatoire(int taille);
void afficher_grille_masque(char** solution, char** masque);
void release_mat(char*** mat);

#endif //PROJET_TAKUZU_FUNCTIONS_H
