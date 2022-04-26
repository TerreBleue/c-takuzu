#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "functions.h"
#include "menu.h"
#include "mat.h"
#include "jeu.h"


#define VIES 3

int main(void) {
    srand((unsigned int) time(NULL));

    char** dyn_masque = masque_aleatoire(SIZE);
    int** mat = static_to_dynamic(m4, SIZE);

    jouer(mat, dyn_masque, VIES);

    // libération finale des éléments dynamiques
    for (int i = 0; i < SIZE; ++i) free(dyn_masque[i]);
    free(dyn_masque);
    dyn_masque = NULL;
    release_mat(&mat, SIZE);
    return 0;
}
