#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "functions.h"
#include "menu.h"
#include "mat.h"

#define SIZE 4

int main(void) {
    char masque[SIZE][SIZE] = {"0011", "0101", "0000", "1111"};
    /*
    char** dyn_masque = (char**) calloc(SIZE, sizeof(char*));
    for (int i = 0; i < SIZE; i++) {
        dyn_masque[i] = (char*) calloc(SIZE, sizeof(char));
        dyn_masque[i] = "0011";
    }
     */
    char** dyn_masque = masque_aleatoire(SIZE);

    int** mat = static_to_dynamic(m4, SIZE);
    afficher_grille(mat, dyn_masque);


    for (int i = 0; i < SIZE; ++i) free(dyn_masque[i]);
    free(dyn_masque);
    release_mat(mat, SIZE);
    return 0;
}
