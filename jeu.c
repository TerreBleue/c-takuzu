#include "jeu.h"

bool grille_completee(char** masque) {
    int taille = size(masque);
    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; j++) if (masque[i][j] != '1') return false;
    }
    return true;
}

void jouer(char** sol, char** masque, int vies) {
    int taille = size(sol), i_lig, i_col;
    char val_entree, emplacement[2] = "", ** grille_jeu = creer_masque(taille);

    printf("Entrer l'emplacement (indices ligne et colonne) et la valeur sous la forme : lignecolonne valeur\n");
    while (vies > 0 && grille_completee(masque) == false) { // jeu
        actualiser_grille_jeu(sol, masque, grille_jeu);
        afficher_grille(grille_jeu);

        do {
            printf("empl et val=");
            scanf("%2s %c", emplacement, &val_entree);
            i_lig = (int) (emplacement[0] - '1'), i_col = (int) (emplacement[1] - 'A');
        } while ('1' + taille - 1 < emplacement[0] || emplacement[0] < '1' // ligne
                 || 'A' + taille - 1 < emplacement[1] || emplacement[1] < 'A' // colonne
                 || val_entree != '0' && val_entree != '1'
                 || masque[i_lig][i_col] == '1'); // valeur déjà affichée

        if (sol[i_lig][i_col] == val_entree) { // si correct
            printf("Coup correct !\n");
            masque[i_lig][i_col] = '1';
        } else {
            printf("Coup incorrect... Il vous reste %d vie(s).\n", --vies);
            printf("\n");
            donner_indice(grille_jeu);
        }
    }

    afficher_grille(grille_jeu);
    if (vies == 0) {
        printf("Vous avez perdu ! Il ne vous reste plus de vies.");
    } else { printf("Vous avez gagné !"); }

}
