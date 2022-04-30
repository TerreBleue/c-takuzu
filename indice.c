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

    int bin = 1, temp = -1;
    while (++temp < taille) {
        if (mat[i][temp] != mat[j][temp]) bin--;
        if (bin < 0) return false;
    }
    return true;
}

bool colonnes_similaires(char **mat, int i, int j) {
    bool sont_similaires = true;
    int temp, taille = size(mat), bin = 1;
    char *str = (char *) calloc(taille + 1, sizeof(char)),
            *str2 = (char *) calloc(taille + 1, sizeof(char));

    for (temp = 0; temp < taille; ++temp) {
        str[temp] = mat[temp][i];
        str2[temp] = mat[temp][j];
    }
    str[taille] = '\0', str2[taille] = '\0';
    if (nombre_manquants(str) != 2 || nombre_manquants(str2) != 0) sont_similaires = false;

    temp = -1;
    while (sont_similaires == true && ++temp < taille) {
        if (str[temp] != str2[temp]) bin--;
        if (bin < 0) sont_similaires = false;
    }

    free(str), free(str2);
    str = NULL, str2 = NULL;
    return sont_similaires;
}

int donner_indice(char **mat, char **sol, int *i_res1, int *i_res2, char *nb_ind) {
    int taille = size(mat), bin, res, temp;
    bool indice_trouve = false;
    char nb_teste;


    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            if (mat[i][j] == INCONNUE) {
                bin = -1;
                while (indice_trouve == false && ++bin < 2) {
                    nb_teste = (char) ('0' + bin);

                    if (si_suite(mat, nb_teste, i, j) == true) {
                        *i_res1 = i, *i_res2 = j;
                        *nb_ind = nb_teste;
                        return 0;
                    } else if (si_entoure(mat, nb_teste, i, j)) {
                        *i_res1 = i, *i_res2 = j;
                        *nb_ind = nb_teste;
                        return 1;
                    }
                }
            }

            if (indice_trouve == false) { // TODO fix
                indice_trouve = lignes_similaires(mat, i, j);
                if (indice_trouve == true) {
                    *i_res1 = i, *i_res2 = j;
                    return 2;
                }
            } else {
                indice_trouve = colonnes_similaires(mat, i, j);
                if (indice_trouve == true) {
                    *i_res1 = i, *i_res2 = j;
                    return 3;
                }
            }
        }
    }

    // pas d'indice trouvé, on donne une case au hasard
    int n, m;
    do {
        n = rand() % taille, m = rand() % taille;
    } while (mat[n][m] != INCONNUE);
    *i_res1 = n, *i_res2 = m;
    return -1;
}

void afficher_indice(char **sol, int code, int i_res1, int i_res2, char nb_ind) {
    char inv = nb_ind == '1' ? '0' : '1';
    switch (code) {
        case 0:
            printf("Aux bouts d'une suite de deux %c, il ne peut y avoir qu’un %c.\n",
                   nb_ind, inv);
            printf("Emplacement : %d%c\n", i_res1 + 1, i_res2 + 'A');
            break;
        case 1:
            printf("Entre deux %c, il ne peut y avoir qu’un %c.\n", nb_ind, inv);
            printf("Emplacement : %d%c\n", i_res1 + 1, i_res2 + 'A');
        case 2:
            printf("Il ne peut pas y avoir deux lignes identiques dans une grille.\n"
                   "Lignes : %d et %d\n", i_res1 + 1, i_res2 + 1);
        case 3:
            printf("Il ne peut pas y avoir deux colonnes identiques dans une grille.\n"
                   "Colonnes : %c et %c\n", i_res1 + 'A', i_res2 + 'A');
        case -1:
            printf("Pas d'indice obtenable, voici une case choisie au hasard : valeur %c à l'emplacement %d%c\n",
                   sol[i_res1][i_res2], i_res1 + 1, i_res2 + 'A');
        default:
            printf("Code non pris en charge\n");
    }
}
