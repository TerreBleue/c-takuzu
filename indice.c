#include "indice.h"

int nombre_manquants(const char *str) {
    int taille = (int) strlen(str), cpt = 0;
    for (int i = 0; i < taille; ++i) if (str[i] == INCONNUE) cpt++;
    return cpt;
}

bool si_suite(char **mat, char nb_teste, int i, int j) {
    int taille = size(mat);
    if (i < taille - 2 && mat[i + 1][j] == nb_teste && mat[i + 2][j] == nb_teste
        || j < taille - 2 && mat[i][j + 1] == nb_teste && mat[i][j + 2] == nb_teste
        || i > 1 && mat[i - 1][j] == nb_teste && mat[i - 2][j] == nb_teste
        || j > 1 && mat[i][j - 1] == nb_teste && mat[i][j - 2] == nb_teste
            ) {
        return true;
    }
    return false;
}

bool si_entoure(char **mat, char nb_teste, int i, int j) {
    int taille = size(mat);
    if (0 < i && i < taille - 1 && mat[i - 1][j] == nb_teste && mat[i + 1][j] == nb_teste
        || 0 < j && j < taille - 1 && mat[i][j - 1] == nb_teste && mat[i][j + 1] == nb_teste) {
        return true;
    }
    return false;
}

bool lignes_similaires(char **mat, int i, int j) {
    int taille = size(mat);
    if (nombre_manquants(mat[i]) != 2 || nombre_manquants(mat[j]) != 0) return false;

    int nb_diff = 0, i_col = -1;
    while (++i_col < taille) if (mat[i][i_col] != mat[j][i_col]) nb_diff++;

    if (nb_diff != 2) return false;
    return true;
}

bool colonnes_similaires(char **mat, int i, int j) {
    bool sont_similaires = true;
    int i_lig, taille = size(mat), nb_diff = 0;
    char *col1 = (char *) calloc(taille + 1, sizeof(char)),
            *col2 = (char *) calloc(taille + 1, sizeof(char));

    for (i_lig = 0; i_lig < taille; ++i_lig) {
        col1[i_lig] = mat[i_lig][i];
        col2[i_lig] = mat[i_lig][j];
    }

    if (nombre_manquants(col1) != 2 || nombre_manquants(col2) != 0) sont_similaires = false;

    i_lig = -1;
    while (sont_similaires == true && ++i_lig < taille) if (col1[i_lig] != col2[i_lig]) nb_diff++;

    if (nb_diff != 2) sont_similaires = false;

    free(col1), free(col2);
    col1 = NULL, col2 = NULL;
    return sont_similaires;
}

void modifier_indice(INDICE *indice, int i, int j, char nb_bin) {
    indice->val_principale = i, indice->val_secondaire = j;
    indice->nombre_binaire = nb_bin;
}

void donner_indice(INDICE *indice, char **mat) {
    int taille = size(mat), i, j, bin;
    char nb_teste;

    for (i = 0; i < taille; ++i) {
        for (j = 0; j < taille; ++j) {
            if (mat[i][j] == INCONNUE) {
                bin = -1;
                while (++bin < 2) {
                    nb_teste = (char) ('0' + bin);

                    if (si_suite(mat, nb_teste, i, j)) {
                        indice->code = 0;
                        nb_teste = inv_bool(nb_teste);
                        return modifier_indice(indice, i, j, nb_teste);
                    } else if (si_entoure(mat, nb_teste, i, j)) {
                        indice->code = 1;
                        nb_teste = inv_bool(nb_teste);
                        return modifier_indice(indice, i, j, nb_teste);
                    }
                }
            }

            if (lignes_similaires(mat, i, j)) {
                indice->code = 2;
                return modifier_indice(indice, i, j, '\0');
            }

            if (colonnes_similaires(mat, i, j)) {
                indice->code = 3;
                return modifier_indice(indice, i, j, '\0');
            }
        }
    }

    // pas d'indice trouvé, on donne une case au hasard
    do {
        i = rand() % taille, j = rand() % taille;
    } while (mat[i][j] != INCONNUE);
    indice->code = -1;
    return modifier_indice(indice, i, j, mat[i][j]);
}

void afficher_indice(char **sol, INDICE indice) {
    switch (indice.code) {
        case 0:
            printf("Aux bouts d'une suite de deux %c, il ne peut y avoir qu’un %c.\n"
                   "Emplacement : %d%c\n",
                   inv_bool(indice.nombre_binaire), indice.nombre_binaire,
                   indice.val_principale + 1, indice.val_secondaire + 'A');
            break;
        case 1:
            printf("Entre deux %c, il ne peut y avoir qu’un %c.\n",
                   "Emplacement : %d%c\n",
                   inv_bool(indice.nombre_binaire), indice.nombre_binaire,
                   indice.val_principale + 1, indice.val_secondaire + 'A');
            break;
        case 2:
            printf("Il ne peut pas y avoir deux lignes identiques dans une grille.\n"
                   "Lignes : %d et %d\n", indice.val_principale + 1, indice.val_secondaire + 1);
            break;
        case 3:
            printf("Il ne peut pas y avoir deux colonnes identiques dans une grille.\n"
                   "Colonnes : %c et %c\n", indice.val_principale + 'A', indice.val_secondaire + 'A');
            break;
        case -1:
            printf("Pas d'indice obtenable, voici une case choisie au hasard - valeur : %c, emplacement : %d%c\n",
                   sol[indice.val_principale][indice.val_secondaire],
                   indice.val_principale + 1, indice.val_secondaire + 'A');
            break;
        default:
            printf("Code non pris en charge\n");
            break;
    }
}
