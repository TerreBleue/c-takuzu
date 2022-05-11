#ifndef PROJET_TAKUZU_GENERATION_H
#define PROJET_TAKUZU_GENERATION_H

#include "functions.h"
#include "masque.h"
#include <math.h>
#include <time.h>

/**
 * Génère automatiquement une grille solution de taille donnée.
 * @param taille La taille de la matrice
 * @return Un pointeur vers la grille solution générée
 */
char** generer_grille(int taille);

#endif //PROJET_TAKUZU_GENERATION_H
