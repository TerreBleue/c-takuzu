#include "functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char** creer_masque(int Taille) {
    char** masque = (char**) calloc(Taille, sizeof(char*));
    for (int i = 0; i < Taille; i++) {
        masque[i] = (char*) calloc((Taille+1), sizeof(char));
    }
    return masque;
}
char** masque_manuel(int Taille) {
    char** masque = creer_masque(Taille);
    char* ligne_masque = calloc(Taille, sizeof(char));
    bool ligne_est_binaire;
    for (int i = 0; i < Taille; i++) {
        printf("Entrer masque[%d]", i);
        do {
            scanf("%s", ligne_masque);
            ligne_est_binaire = true;
            for (int j = 0; j < strlen(ligne_masque); j++) {
                if (ligne_masque[j] != '1' && ligne_masque[j] != '0') {
                    continue;
                }
                ligne_est_binaire = false;
            }
        } while (strlen(ligne_masque) != Taille && ligne_est_binaire == false);
        masque[i] = ligne_masque;
    }
    free(ligne_masque);
    return masque;
}

void afficher_grille(int** mat_solution, char** masque) {
    int taille = (int) strlen(masque[0]);
    for (int i = 0; i < taille; ++i) {
        printf("%d", i + 1);
    }
    printf("\n");
    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            if (masque[i][j] == '1') { printf("%d", mat_solution[i][j]); }
            else { printf(" "); }
        }
        printf(" %c\n", 'A' + i);
    }
}

int** static_to_dynamic(int** mat, int n) {
    int** new_mat = calloc(n, sizeof(int*));
    for (int i = 0; i < n; ++i) {
        new_mat[i] = calloc(n, sizeof(int));
    }
    return new_mat;
}

void release_mat(int** mat, int n) {
    for (int i = 0; i < n; ++i) free(mat[i]);
    free(mat);
}

char** masque_aleatoire(int taille) {
    char** masque = creer_masque(taille);
    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            masque[i][j] = (char) ('0' + rand() % 2);
        }
    }
    return masque;
}
