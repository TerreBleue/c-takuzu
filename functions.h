#ifndef PROJET_TAKUZU_FUNCTIONS_H
#define PROJET_TAKUZU_FUNCTIONS_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define VIES 3
#define INCONNUE '.'


void pause();
void clear();
char inv_bool(char bin);
int size(char** str);
char** static_to_dynamic(int taille);
void actualiser_grille_jeu(char** sol, char** masque, char** grille_jeu);
void afficher_grille(char** grille);
void afficher_grille_masque(char** solution, char** masque);
void release_mat(char*** mat);
bool grille_completee(char** grille);
int grille_correcte(char **grille);

#endif //PROJET_TAKUZU_FUNCTIONS_H
