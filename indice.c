#include "indice.h"

int nombre_manquants(const char* str) {
    int taille = (int) strlen(str), cpt = 0;
    for (int i = 0; i < taille; ++i) if (str[i] == INCONNUE) cpt++;
    return cpt;
}

void donner_indice(char** mat) {
    int taille = size(mat), bin;
    bool indice_trouve = false;
    char nb_teste, inv_nb, *str = (char*) calloc(taille, sizeof(char));

    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            if (mat[i][j] != INCONNUE) continue;

            bin = -1;
            while (indice_trouve == false && ++bin < 2) {
                nb_teste = (char) ('0' + bin), inv_nb = (char) ('1' - bin);

                if (0 < i && i < taille - 2 && mat[i + 1][j] == nb_teste && mat[i + 2][j] == nb_teste
                    || 1 < i && i < taille - 1 && mat[i - 1][j] == nb_teste && mat[i - 2][j] == nb_teste
                    || 0 < j && j < taille - 2 && mat[i][j + 1] == nb_teste && mat[i][j + 2] == nb_teste
                    || 1 < j && j < taille - 1 && mat[i][j - 1] == nb_teste && mat[i][j - 2] == nb_teste
                        ) {
                    printf("Au-dessus, en dessous, à gauche, à droite d’une série de deux %c, il ne peut y avoir qu’un %c.\n",
                           nb_teste, inv_nb);
                    indice_trouve = true;
                } else if (
                        0 < i && i < taille - 1 && mat[i - 1][j] == nb_teste && mat[i + 1][j] == nb_teste
                        || 0 < j && j < taille - 1 && mat[i][j - 1] == nb_teste && mat[i][j + 1] == nb_teste) {
                    printf("Entre deux %c, il ne peut y avoir qu’un %c.\n", inv_nb, nb_teste);
                    indice_trouve = true;
                }

                if (indice_trouve == true) {
                    printf("Emplacement recommandé : %d%c\n", i + 1, j + 'A');
                }
            }

            if (indice_trouve == false && nombre_manquants(mat[i]) == 2) {
                if (j == i) continue;
                indice_trouve = true;
                for (int k = 0; k < taille; k++) {
                    if (mat[i][k] != mat[j][k]) {
                        indice_trouve = false;
                        break;
                        // une boucle while a été initialement écrite pour éviter break, mais cela crée un warning dans l'IDE
                    }
                }

                if (indice_trouve == true) {
                    printf("Il ne peut pas y avoir deux lignes identiques dans une grille.\n"
                           "Lignes en question : %d et %d\n", i + 1, j + 1);
                }

            }

            if (indice_trouve == false) {
                for (int temp = 0; temp < taille; ++temp) str[temp] = mat[temp][i];
                if (nombre_manquants(str) == 2) {
                    if (j == i) continue;
                    indice_trouve = true;

                    for (int k = 0; k < taille; k++) {
                        if (mat[k][i] != mat[k][j]) {
                            indice_trouve = false;
                            break;
                        }
                    }

                    if (indice_trouve == true) {
                        printf("Il ne peut pas y avoir deux colonnes identiques dans une grille.\n"
                               "Colonnes en question : %d et %d\n", i + 1, j + 1);
                    }

                }
            }

            if (indice_trouve == true) {
                free(str);
                str = NULL;
                return;
            }
        }
    }

    free(str);
    str = NULL;
    // pas d'indice trouvé, on donne une case au hasard
    int n = rand() % taille, m = rand() % taille;
    while (mat[n][m] != INCONNUE) {
        n = rand() % taille, m = rand() % taille;
    }

    return (void) printf("Pas d'indice trouvé, voici une case random : valeur '%c' à l'emplacement %d%c\n",
                         mat[n][m], n + 1, m + 'A');
}
