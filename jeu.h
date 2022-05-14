#ifndef PROJET_TAKUZU_JEU_H
#define PROJET_TAKUZU_JEU_H
#include "fonctions.h"
#include "indice.h"
#include "masque.h"

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/**
 * Jouer au Takuzu à l'aide d'une solution et d'un masque déjà générés.
 *
 * @param sol Grille solution
 * @param masque Grille masque
 * @param vies Nombre de vies, de coups incorrects que le joueur peut entrer au maximum
 */
void jouer(char **sol, char **masque, int vies);

#endif //PROJET_TAKUZU_JEU_H
