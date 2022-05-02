
#include "functions.h"

void pause() {
    sleep(5);
    printf("---------------------------------\n");
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
            "10110100",
            "10101001",
            "01011010",
            "01010110",
            "10100101",
            "01001011",
            "00110110",
            "11001001"
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
    printf("\n");

    // affichage indice des colonnes
    for (int i = 0; i < taille; ++i) printf("%c ", 'A' + i);
    printf("\n");
    for (int i = 0; i < taille; ++i) printf("| ");
    printf("\n");

    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) printf("%c ", grille[i][j]);
        printf("- %d\n", i + 1); // affichage indice lignes
    }
}

bool grille_completee(char **grille) {
    int taille = size(grille);
    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; j++) if (grille[i][j] == INCONNUE) return false;
    }
    return true;
}

int grille_correcte(char **grille) {
    int taille = size(grille);
    int cpt_lig_0, cpt_col_0, cpt_lig_1, cpt_col_1, cpt_sim_lig, cpt_sim_col, cpt_suite_lig, cpt_suite_col;
    char suite_lig, suite_col;
    for (int i = 0; i < taille; ++i) {
        cpt_lig_0 = 0, cpt_col_0 = 0, cpt_lig_1 = 0, cpt_col_1 = 0;
        cpt_suite_lig = 0, cpt_suite_col = 0;
        for (int j = 0; j < taille; ++j) {
            if (i != j) {
                cpt_sim_lig = 0, cpt_sim_col = 0;
                for (int k = 0; k < taille; ++k) {
                    if (grille[i][k] != INCONNUE && grille[i][k] == grille[j][k]) cpt_sim_lig++;
                    if (grille[k][i] != INCONNUE && grille[k][i] == grille[k][j]) cpt_sim_col++;
                }
                if (cpt_sim_lig == taille || cpt_sim_col == taille) {
                    printf("lig %d col %d", cpt_sim_lig, cpt_sim_col);
                    return -3;
                }
            }

            if (grille[i][j] == '0') cpt_lig_0++;
            if (grille[j][i] == '0') cpt_col_0++;
            if (grille[i][j] == '1') cpt_lig_1++;
            if (grille[j][i] == '1') cpt_col_1++;

            if (j == 0) {
                suite_lig = grille[i][j];
                suite_col = grille[j][i];
            }
            if (suite_lig == grille[i][j]) { cpt_suite_lig++; }
            else {
                suite_lig = grille[i][j];
                cpt_suite_lig = 1;
            }

            if (suite_col == grille[j][i]) { cpt_suite_col++; }
            else {
                suite_col = grille[j][i];
                cpt_suite_col = 1;
            }

            if (cpt_lig_0 > taille / 2 || cpt_col_0 > taille / 2 || cpt_lig_1 > taille / 2 || cpt_col_1 > taille / 2) {
                return -1;
            }
            if (suite_lig != INCONNUE && cpt_suite_lig > 2 || suite_col != INCONNUE && cpt_suite_col > 2) return -2;
        }
    }

    return 1;
}
