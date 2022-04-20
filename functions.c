#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include "mat.h"

bool good_colonne(int **Grille, int *colonne, int Taille) {
    if (Taille == 4) {
        ;
    }
}

int ** creer_masque(int** tableau, int Taille){
    int ** masque = calloc(Taille, sizeof(int*));
    for(int i=0; i<Taille;i++){
        masque[i] = calloc(Taille, sizeof(int));
    }
    char* ligne_masque ;
    for(int i=0; i<Taille;i++){
        printf("Entrer masque[%d]", i);
        scanf("%s",ligne_masque);

    }
}