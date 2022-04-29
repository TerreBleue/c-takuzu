#include "indice.h"

int nombre_manquants(const char* str) {
    int taille = (int) strlen(str), cpt = 0;
    for (int i = 0; i < taille; ++i) if (str[i] == 'X') cpt++;
    return cpt;
}

void donner_indice(char** grille_jeu) {
    int taille = (int) strlen(grille_jeu[0]);
    bool indice_trouve = false, chaine_correspond;
    char str[SIZE] = "";

    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            if (grille_jeu[i][j] != 'X') continue;

            if (0 < i && i < taille - 2 && grille_jeu[i + 1][j] == '0' && grille_jeu[i + 2][j] == '0'
                || 1 < i && i < taille - 1 && grille_jeu[i - 1][j] == '0' && grille_jeu[i - 2][j] == '0'
                || 0 < j && j < taille - 2 && grille_jeu[i][j + 1] == '0' && grille_jeu[i][j + 2] == '0'
                || 1 < j && j < taille - 1 && grille_jeu[i][j - 1] == '0' && grille_jeu[i][j - 2] == '0'
                    ) {
                printf("Au-dessus, en dessous, à gauche, à droite d’une série de deux 0, il ne peut y avoir qu’un 1.\n");
                indice_trouve = true;
            } else if (0 < i && i < taille - 2 && grille_jeu[i + 1][j] == '1' && grille_jeu[i + 2][j] == '1'
                       || 1 < i && i < taille - 1 && grille_jeu[i - 1][j] == '1' && grille_jeu[i - 2][j] == '1'
                       || 0 < j && j < taille - 2 && grille_jeu[i][j + 1] == '1' && grille_jeu[i][j + 2] == '1'
                       || 1 < j && j < taille - 1 && grille_jeu[i][j - 1] == '1' && grille_jeu[i][j - 2] == '1'
                    ) {
                printf("Au-dessus, en dessous, à gauche, à droite d’une série de deux 1, il ne peut y avoir qu’un 0.\n");
                indice_trouve = true;

            } else if (0 < i && i < taille - 1 && grille_jeu[i - 1][j] == '0' && grille_jeu[i + 1][j] == '0'
                       || 0 < j && j < taille - 1 && grille_jeu[i][j - 1] == '0' && grille_jeu[i][j + 1] == '0') {
                printf("Entre deux 0, il ne peut y avoir qu’un 1.\n");
                indice_trouve = true;
            } else if (0 < i && i < taille - 1 && grille_jeu[i - 1][j] == '1' && grille_jeu[i + 1][j] == '1'
                       || 0 < j && j < taille - 1 && grille_jeu[i][j - 1] == '1' && grille_jeu[i][j + 1] == '1') {
                printf("Entre deux 1, il ne peut y avoir qu’un 0.\n");
                indice_trouve = true;
            }

            if (indice_trouve == true) return (void) printf("Emplacement recommandé : %d%c\n", i + 1, j + 'A');
        }

        if (nombre_manquants(grille_jeu[i]) == 2) {
            for (int i_lig = 0; i_lig < taille; ++i_lig) {
                if (i_lig == i) continue;
                chaine_correspond = true;

                for (int k = 0; k < taille; k++) {
                    if (grille_jeu[i][k] != grille_jeu[i_lig][k]) {
                        chaine_correspond = false;
                        break;
                    }
                }

                if (chaine_correspond == true) {
                    return (void) printf("Il ne peut pas y avoir deux lignes identiques dans une grille.\n"
                                         "Lignes en question : %d et %d\n", i + 1, i_lig + 1);
                }
            }
        }

        for (int temp = 0; temp < taille; ++taille) str[temp] = grille_jeu[temp][i];
        if (nombre_manquants(str) == 2) {
            for (int i_col = 0; i_col < taille; ++i_col) {
                if (i_col == i) continue;
                chaine_correspond = true;

                for (int k = 0; k < taille; k++) {
                    if (grille_jeu[k][i] != grille_jeu[k][i_col]) {
                        chaine_correspond = false;
                        break;
                    }
                }

                if (chaine_correspond == true) {
                    return (void) printf("Il ne peut pas y avoir deux colonnes identiques dans une grille.\n"
                                         "Colonnes en question : %d et %d\n", i + 1, i_col + 1);
                }
            }
        }
    }

    // pas d'indice trouvé, on donne une case au hasard
    int n = rand() % taille, m = rand() % taille;
    while (grille_jeu[n][m] != 'X') n = rand() % taille, m = rand() % taille;
    return (void) printf("Pas d'indice trouvé, voici une case random : '%d' à l'emplacement %d%c\n",
                         grille_jeu[n][m], n + 1, m + 'A');
}

