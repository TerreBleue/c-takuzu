
#include "functions.h"

void pause() {
    sleep(5);
    printf("\n---------------------------------\n");
}

char inv_bool(char bin) {
    return bin == '1' ? '0' : '1';
}

int size(char **str) {
    return (int) strlen(str[0]);
}

char **creer_masque(int taille) {
    char **masque = (char **) calloc(taille, sizeof(char *));
    for (int i = 0; i < taille; i++) {
        masque[i] = (char *) calloc((taille + 1), sizeof(char));
    }
    return masque;
}

char **masque_manuel(int taille) {
    char **masque = creer_masque(taille);
    char *ligne_masque = (char *) calloc(taille + 1, sizeof(char));
    bool ligne_est_binaire;
    int j;

    printf("Entrer les lignes du masque\n");
    for (int i = 0; i < taille; i++) {
        do {
            printf("masque[%d]=", i);
            scanf("%s", ligne_masque);
            ligne_est_binaire = true;
            j = -1;

            while (ligne_est_binaire == true && ++j < strlen(ligne_masque)) {
                if (ligne_masque[j] != '1' && ligne_masque[j] != '0') ligne_est_binaire = false;
            }

        } while (strlen(ligne_masque) != taille || ligne_est_binaire == false);
        strcpy(masque[i], ligne_masque);
    }

    free(ligne_masque);
    ligne_masque = NULL;
    return masque;
}

void afficher_grille_masque(char **solution, char **masque) {
    int taille = size(solution);

    // affichage indice des colonnes
    for (int i = 0; i < taille; ++i) printf("%c ", 'A' + i);
    printf("\n");
    for (int i = 0; i < taille; ++i) printf("| ");
    printf("\n");

    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            if (masque[i][j] == '1') {
                printf("%c ", solution[i][j]);
            } else {
                printf("%c ", INCONNUE);
            }
        }
        printf("- %d\n", i + 1); // affichage indice lignes
    }
    printf("\n");
}

char **static_to_dynamic(int taille) {
    char m4[4][4] = {
            "0011",
            "0110",
            "1001",
            "1100"
    };

    char m8[8][8] = {
            "00001111",
            "00111100",
            "01001011",
            "01111000",
            "10000111",
            "10110100",
            "11000011",
            "11100001"
    };

    char **new_mat = (char **) calloc(taille, sizeof(char *));
    for (int i = 0; i < taille; ++i) {
        new_mat[i] = (char *) calloc(taille, sizeof(char));
        switch (taille) {
            case 4:
                strncpy(new_mat[i], m4[i], taille);
                break;
            case 8:
                strncpy(new_mat[i], m8[i], taille);
                break;
            default:
                printf("La taille de matrice %d n'est pas prise en charge.\n", taille);
        }
    }
    return new_mat;
}

void release_mat(char ***mat) {
    int taille = (int) strlen((*mat)[0]);
    for (int i = 0; i < taille; ++i) free((*mat)[i]);
    free(*mat);
    *mat = NULL;
}

char **masque_aleatoire(int taille) {
    char **masque = creer_masque(taille);
    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            masque[i][j] = (char) ('0' + rand() % 2);
        }
    }
    return masque;
}

void actualiser_grille_jeu(char **sol, char **masque, char **grille_jeu) {
    int taille = size(sol);
    for (int i = 0; i < taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (masque[i][j] == '1') {
                grille_jeu[i][j] = sol[i][j];
            } else {
                grille_jeu[i][j] = INCONNUE;
            }
        }
    }
}

void afficher_grille(char **grille) {
    int taille = size(grille);

    // affichage indice des colonnes
    for (int i = 0; i < taille; ++i) printf("%c ", 'A' + i);
    printf("\n");
    for (int i = 0; i < taille; ++i) printf("| ");
    printf("\n");

    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) printf("%c ", grille[i][j]);
        printf("- %d\n", i + 1); // affichage indice lignes
    }
    return (void) printf("\n");
}

void release_masque(char ***masque) {
    int taille = size(*masque);
    for (int i = 0; i < taille; ++i) free((*masque)[i]);
    free(*masque);
    *masque = NULL;
}
