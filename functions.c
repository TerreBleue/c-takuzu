#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include "mat.h"

bool good_colonne(int **Grille, int *colonne, int Taille) {
    if (Taille == 4) { ;
    }
}

char ** creer_masque(int Taille) {
    char **masque = calloc(Taille, sizeof(char*));
    for (int i = 0; i < Taille; i++) {
        masque[i] = calloc(Taille, sizeof(char));
    }
    char *ligne_masque;
    for (int i = 0; i < Taille; i++) {
        printf("Entrer masque[%d]", i);
        scanf("%s", ligne_masque);

    }
}