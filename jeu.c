#include "jeu.h"

bool grille_completee(char** masque) {
    int taille = (int) strlen(masque[0]);
    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; j++) if (masque[i][j] != '1') return false;
    }
    return true;
}

void jouer(int** tab, char** masque, int vies) {
    afficher_grille(tab, masque);

    int taille = (int) strlen(masque[0]), val_entree;
    char emplacement[2] = "";
    bool est_correct;

    printf("Entrer l'emplacement (indices ligne et colonne) et la valeur sous la forme : lignecolonne valeur\n");
    while (vies > 0 && grille_completee(masque) == false) { // jeu
        printf("emplacement (ligne colonne) et valeur =");
        do { scanf("%2s %1d", emplacement, &val_entree); }
        while ('1' <= emplacement[0] && emplacement[0] <= '1' + taille - 1
               && 'A' <= emplacement[1] && emplacement[1] <= 'A' + taille - 1
               && (val_entree == 0 || val_entree == 1)
               && masque[(int) (emplacement[0] - '1')][(int) (emplacement[1] - 'A')] == '1');
        // comparer avec grille solution
    }
}
