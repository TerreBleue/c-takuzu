#ifndef PROJET_TAKUZU_GENERATION_H
#define PROJET_TAKUZU_GENERATION_H

#include "fonctions.h"
#include "masque.h"
#include <math.h>

/**
 * Génère automatiquement une grille solution de taille donnée.
 * @param taille La taille de la matrice
 * @return Un pointeur vers la grille solution générée
 */
char** generer_grille(int taille);

/**
 * Affiche toutes les lignes correctes possibles d'une taille donnée.
 * @param taille La taille
 */
void afficher_lignes_correctes(int taille);

/**
 * Génère une grille solution et affiche chaque grille avec les lignes correctes.
 * @param taille La taille de la grille
 * @return Rien, cela permet simplement d'afficher la manière de générer la grille.
 */
void afficher_generation(int taille);

#endif //PROJET_TAKUZU_GENERATION_H
