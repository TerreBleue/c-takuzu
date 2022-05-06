#include "generation.h"


void appliquer_indices(char **grille) {
    INDICE indice;
    int taille = size(grille);
    do {
        donner_indice(&indice, grille);
        if (indice.code == 0 || indice.code == 1) {
            grille[indice.val_principale][indice.val_secondaire] = indice.nombre_binaire;
        } else if (indice.code == 2) {
            strcpy(grille[indice.val_principale], grille[indice.val_secondaire]);
        } else if (indice.code == 3) {
            for (int j = 0; j < taille; ++j) {
                grille[j][indice.val_principale] = grille[j][indice.val_secondaire];
            }
        }
    } while (indice.code != -1);
}

char **copier_grille(char **grille) {
    int taille = size(grille);
    char **mat = creer_masque(taille);

    for (int i = 0; i < taille; ++i) strcpy(mat[i], grille[i]);
    return mat;
}

char **generation_rec(char **grille, int lig, int col) {
    if (grille_correcte(grille) < 0) return NULL;
    char **temp = copier_grille(grille), **res1 = NULL, **res2 = NULL;

    if (grille_completee(temp)) return temp;

    int taille = size(grille);
    int t_lig = lig, t_col = col;
    char tab_choix[2];
    tab_choix[0] = (char) (rand() % 2 + '0');
    tab_choix[1] = inv_bool(tab_choix[0]);
    for (int i_choix = 0; i_choix < 2; ++i_choix) {
        while (t_lig < taille - 1 && temp[t_lig + 1][col] != INCONNUE) t_lig++;
        if (t_lig < taille - 1) {
            temp[t_lig + 1][col] = tab_choix[i_choix];
            appliquer_indices(temp);
            res1 = generation_rec(temp, t_lig + 1, col);

            if (res1 != NULL) {
                release_mat(&temp);
                return res1;
            }
        }
        if (temp != NULL) release_mat(&temp);
        temp = copier_grille(grille);

        while (t_col < taille - 1 && temp[lig][t_col + 1] != INCONNUE) t_col++;
        if (col < taille - 1) {
            temp[lig][t_col + 1] = tab_choix[i_choix];
            appliquer_indices(temp);
            res2 = generation_rec(temp, lig, t_col + 1);

            if (res2 != NULL) {
                release_mat(&temp);
                return res2;
            }
        }
        if (temp != NULL) release_mat(&temp);
        temp = copier_grille(grille);
    }
    return NULL;
}

char **generer_grille(int taille) {
    clock_t tic = clock();
    char **grille = creer_masque(taille), **res;
    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) grille[i][j] = INCONNUE;
    }
    res = generation_rec(grille, 0, 0);
    if (grille != NULL) release_mat(&grille);
    clock_t toc = clock();
    printf("Temps de génération de la grille : %f\n", (toc - tic) / CLOCKS_PER_SEC);
    return res;
}
