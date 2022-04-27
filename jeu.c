#include "jeu.h"

bool grille_completee(char** masque) {
    int taille = (int) strlen(masque[0]);
    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; j++) if (masque[i][j] != '1') return false;
    }
    return true;
}

void jouer(int** tab, char** masque, int vies) {
    int taille = (int) strlen(masque[0]), val_entree;
    char emplacement[2] = "";
    char** grille_jeu = creer_masque(taille);

    printf("Entrer l'emplacement (indices ligne et colonne) et la valeur sous la forme : lignecolonne valeur\n");
    while (vies > 0 && grille_completee(masque) == false) { // jeu
        actualiser_grille_jeu(tab, masque, grille_jeu);

        do {
            printf("empl et val=");
            scanf("%2s %1d", emplacement, &val_entree);
        } while ('1' + taille - 1 < emplacement[0] || emplacement[0] < '1' // ligne
                 || 'A' + taille - 1 < emplacement[1] || emplacement[1] < 'A' // colonne
                 || val_entree != 0 && val_entree != 1
                 || masque[(int) (emplacement[0] - '1')][(int) (emplacement[1] - 'A')] == '1'); // valeur déjà affichée

        if (tab[(int) (emplacement[0] - '1')][(int) (emplacement[1] - 'A')] == val_entree) { // correct
            printf("Coup correct !\n");
            masque[(int) (emplacement[0] - '1')][(int) (emplacement[1] - 'A')] = '1';
        } else { printf("Coup incorrect... Il vous reste %d vie(s).\n", --vies); }
    }
    afficher_grille(tab, masque);
    if (vies == 0) {
        printf("Vous avez perdu ! Il ne vous reste plus de vies.");
    } else {
        printf("Vous avez gagné !");
    }
}
