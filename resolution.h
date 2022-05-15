#ifndef PROJET_TAKUZU_RESOLUTION_H
#define PROJET_TAKUZU_RESOLUTION_H
#include "fonctions.h"
#include "masque.h"
#include "indice.h"
#include "jeu.h"

/**
 * Résout une grille automatiquement.
 * @param sol Solution
 * @param masque Masque
 * @param vies Nombre de vies
 * @return Rien, cela ne fait que modifier.
 */
void resoudre_grille(char **sol, char **masque, int vies);

#endif //PROJET_TAKUZU_RESOLUTION_H
