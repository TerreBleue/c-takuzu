
#include "functions.h"

void pause() {
    printf("Appuyez sur Enter pour continuer...");
    getchar();
}

char** creer_masque(int taille) {
    char** masque = (char**) calloc(taille, sizeof(char*));
    for (int i = 0; i < taille; i++) {
        masque[i] = (char*) calloc((taille + 1), sizeof(char));
    }
    return masque;
}

char** masque_manuel(int taille) {
    char** masque = creer_masque(taille);
    char* ligne_masque = (char*) calloc(taille + 1, sizeof(char));
    bool ligne_est_binaire;
    int j;

    printf("Entrer les lignes du masque\n");
    for (int i = 0; i < taille; i++) {
        do {
            printf("masque[%d]=", i);
            ligne_masque = "";
            scanf("%s", ligne_masque);
            ligne_est_binaire = true;
            j = -1;

            while (ligne_est_binaire == true && ++j < strlen(ligne_masque)) {
                if (ligne_masque[j] != '1' && ligne_masque[j] != '0') continue;
                ligne_est_binaire = false;
            }
        } while (strlen(ligne_masque) != taille || ligne_est_binaire == false);
        masque[i] = ligne_masque;
    }

    free(ligne_masque);
    ligne_masque = NULL;
    return masque;
}

void afficher_grille(int** mat_solution, char** masque) {
    int taille = (int) strlen(masque[0]);

    // affichage indice des colonnes
    for (int i = 0; i < taille; ++i) printf("%c ", 'A' + i);
    printf("\n");
    for (int i = 0; i < taille; ++i) printf("| ");
    printf("\n");

    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            if (masque[i][j] == '1') {
                printf("%d ", mat_solution[i][j]);
            } else {
                printf("X ");
            }
        }
        printf("- %d\n", i + 1); // affichage indice lignes
    }
    printf("\n");
}

int** static_to_dynamic(const int mat[SIZE][SIZE], int taille) {
    int** new_mat = calloc(taille, sizeof(int*));
    for (int i = 0; i < taille; ++i) {
        new_mat[i] = calloc(taille, sizeof(int));
        for (int j = 0; j < taille; ++j) new_mat[i][j] = mat[i][j];
    }
    return new_mat;
}

void release_mat(int*** mat, int taille) {
    for (int i = 0; i < taille; ++i) free(*mat[i]);
    free(*mat);
    *mat = NULL;
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
