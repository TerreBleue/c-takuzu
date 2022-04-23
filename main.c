#include <stdlib.h>
#include <stdio.h>

#include "functions.h"
#include "menu.h"
#include "mat.h"

#define SIZE 4

int main(void) {
    char masque[SIZE][SIZE] = {"0011", "0101", "0000", "1111"};
    int **mat = static_to_dynamic((int **) m4, SIZE);
    afficher_grille(mat, (char **) masque);

    release_mat(mat, SIZE);
    return 0;
}
