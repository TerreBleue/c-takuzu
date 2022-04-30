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

int donner_indice(char **mat, char **sol, int *i_res1, int *i_res2) {
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
                        printf("Aux bouts d'une suite de deux %c, il ne peut y avoir qu’un %c.\n",
                               nb_teste, '1' - bin);
                        indice_trouve = true;
                    } else if (si_entoure(mat, nb_teste, i, j)) {
                        printf("Entre deux %c, il ne peut y avoir qu’un %c.\n", nb_teste, '1' - bin);
                        indice_trouve = true;
                    }

                    if (indice_trouve == true) {
                        printf("Emplacement : %d%c\n", i + 1, j + 'A');
                        *i_res1 = i, *i_res2 = j;
                        return 1;
                    }
                }
            }

            if (indice_trouve == false) { // TODO fix
                indice_trouve = lignes_similaires(mat, i, j);
                if (indice_trouve == true) {
                    printf("Il ne peut pas y avoir deux lignes identiques dans une grille.\n"
                           "Lignes : %d et %d\n", i + 1, j + 1);
                    *i_res1 = i, *i_res2 = j;
                    return 2;
                }
            } else {
                indice_trouve = colonnes_similaires(mat, i, j);
                if (indice_trouve == true) {
                    printf("Il ne peut pas y avoir deux colonnes identiques dans une grille.\n"
                           "Colonnes : %c et %c\n", i + 'A', j + 'A');
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
    printf("Pas d'indice obtenable, voici une case choisie au hasard : valeur %c à l'emplacement %d%c\n",
           sol[n][m], n + 1, m + 'A');
    *i_res1 = n, *i_res2 = m;
    return -1;
}
