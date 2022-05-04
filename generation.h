#ifndef PROJET_TAKUZU_GENERATION_H
#define PROJET_TAKUZU_GENERATION_H

#include "functions.h"
#include "masque.h"
#include <math.h>

bool verif_code(int code, const int* tab_code, int taille);
bool comparer_lig_prec(int code, int i, char** grille);
void generer_grille(char** grille, int taille);

#endif //PROJET_TAKUZU_GENERATION_H
