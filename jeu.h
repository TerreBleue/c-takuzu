#ifndef PROJET_TAKUZU_JEU_H
#define PROJET_TAKUZU_JEU_H
#include "fonctions.h"
#include "indice.h"
#include "masque.h"

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/**
 * Demande la validation d'un coup entré à un emplacement entré.
 * @param grille La grille de jeu
 * @param sol La grille solution
 * @param i_ligne Indice ligne
 * @param i_colonne Indice colonne
 * @param valeur Valeur binaire entrée
 * @param vies Nombre de vies restantes
 * @return 1 si valide et correct ; 0 si valide mais incorrect ; -1 si invalide.
 */
int valider_coup(char **grille, char **sol, int i_ligne, int i_colonne, char valeur, int *vies);

/**
 * Joue au Takuzu à l'aide d'une solution et d'un masque déjà générés.
 *
 * @param sol Grille solution
 * @param masque Grille masque
 * @param vies Nombre de vies, de coups incorrects que le joueur peut entrer au maximum
 */
void jouer(char **sol, char **masque, int vies);

#endif //PROJET_TAKUZU_JEU_H
