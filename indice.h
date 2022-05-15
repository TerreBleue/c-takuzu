#ifndef PROJET_TAKUZU_INDICE_H
#define PROJET_TAKUZU_INDICE_H
#include "fonctions.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Structure d'indice.\n
 * * code : le numéro de code de l'indice : de 0 à 3 si l'indice est trouvé, sinon -1 s'il est aléatoire\n
 * * val_principale : si l'indice est entre -1 et 1, c'est le numéro de ligne ;
 * sinon c'est la ligne/colonne similaire dont il manque des nombres\n
 * * val_secondaire : si l'indice est entre -1 et 1, c'est le numéro de colonne ;
 * sinon c'est la ligne/colonne similaire entièrement remplie\n
 * * nombre_binaire : si l'indice est entre -1 et 1, c'est la valeur à entrer (sinon il est nul)
 */
typedef struct {
    int code;
    int val_principale;
    int val_secondaire;
    char nombre_binaire;
} INDICE;

/**
 * Donne le nombre d'inconnues dans une chaine de caractères.
 * @param str La chaine de caractères
 * @return Le nombre d'inconnues
 */
int nombre_inconnues(const char *str);

/**
 * Modifie l'indice donné en paramètre selon ce qui peut être donné.\n
 * * -1 : l'indice est introuvable, c'est une valeur aléatoire qui a été donnée\n
 * * 0 : aux bouts d'une suite de deux 0 ou 1, il ne peut y avoir que leur inverse\n
 * * 1 : entre deux mêmes nombres, il ne peut y avoir que leur inverse\n
 * * En comparant une ligne/colonne où il manque 2 valeurs et une autre déjà remplie, si toutes les valeurs correspondent,\n
 * alors on peut remplir la ligne/colonne partielle.\n
 * * * 2 : ce sont des lignes\n
 * * * 3 : ce sont des colonnes\n
 * @param indice L'indice modifié
 * @param mat La grille jeu
 */
void donner_indice(INDICE* indice, char **mat);

/**
 * Affiche l'indice selon la valeur de son code.
 * @param sol Grille solution
 * @param indice L'indice
 */
void afficher_indice(char** sol, INDICE indice);

#endif //PROJET_TAKUZU_INDICE_H
