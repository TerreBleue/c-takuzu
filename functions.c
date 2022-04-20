#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
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
    char * ligne_masque=calloc(Taille, sizeof(char));
    bool ligne_est_binaire;
    for (int i = 0; i < Taille; i++) {
        printf("Entrer masque[%d]", i);
        do {
            scanf("%s", ligne_masque);
            ligne_est_binaire=true;
            for(int j=0;j<strlen(ligne_masque);j++){
                if(ligne_masque[j]!='1' && ligne_masque[j]!='0'){
                    continue;
                }
                ligne_est_binaire=false;
            }
        }while(strlen(ligne_masque)!= Taille && ligne_est_binaire == false);
        masque[i]= ligne_masque;
    }
    free(ligne_masque);
    return masque;
}