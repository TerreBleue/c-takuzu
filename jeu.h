#ifndef PROJET_TAKUZU_JEU_H
#define PROJET_TAKUZU_JEU_H
#include "functions.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool grille_completee(char** masque);
void jouer(int** tab, char** masque, int vies);

void donner_indice(char** grille_jeu) {
    int taille = (int) strlen(grille_jeu[0]);
    bool indice_trouve = false;

    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            if (0 < i && i < taille - 2 && grille_jeu[i + 1][j] == '0' && grille_jeu[i + 2][j] == '0'
                || 1 < i && i < taille - 1 && grille_jeu[i - 1][j] == '0' && grille_jeu[i - 2][j] == '0'
                || 0 < j && j < taille - 2 && grille_jeu[i][j + 1] == '0' && grille_jeu[i][j + 2] == '0'
                || 1 < j && j < taille - 1 && grille_jeu[i][j - 1] == '0' && grille_jeu[i][j - 2] == '0'
                    ) {
                printf("Au-dessus, en dessous, à gauche, à droite d’une série de deux 0, il ne peut y avoir qu’un 1.");
                indice_trouve = true;
            }
            else if (0 < i && i < taille - 2 && grille_jeu[i + 1][j] == '1' && grille_jeu[i + 2][j] == '1'
                     || 1 < i && i < taille - 1 && grille_jeu[i - 1][j] == '1' && grille_jeu[i - 2][j] == '1'
                     || 0 < j && j < taille - 2 && grille_jeu[i][j + 1] == '1' && grille_jeu[i][j + 2] == '1'
                     || 1 < j && j < taille - 1 && grille_jeu[i][j - 1] == '1' && grille_jeu[i][j - 2] == '1'
                    ) {
                printf("Au-dessus, en dessous, à gauche, à droite d’une série de deux 1, il ne peut y avoir qu’un 0.");
                indice_trouve = true;
            } else if ( i < taille-2 && grille_jeu[i][j]=='0' && grille_jeu[i+2][j]=='0'
                        || j< taille-2 && grille_jeu[i][j]=='0' && grille_jeu[i][j+2]=='0') {
                printf("Entre deux 0, il ne peut y avoir qu’un 1.");
                indice_trouve = true;
            }

            if (indice_trouve == true) return (void) printf("Emplacement recommandé : %d%c", i + 1, j + 'A');
        }
    }
}

#endif //PROJET_TAKUZU_JEU_H
