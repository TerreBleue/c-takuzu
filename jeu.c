#include "jeu.h"

bool grille_completee(char** masque) {
    int taille = (int) strlen(masque[0]);
    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; j++) {
            if (masque[i][j] != '1') return false;
        }
    }
    return true;
}

void jouer(int** tab, char** masque, int vies) {
    afficher_grille(tab, masque);
    bool est_correct;
    while (vies > 0 && grille_completee(masque) == false) { // jeu

    }
}
