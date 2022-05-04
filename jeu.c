#include "jeu.h"



void jouer(char **sol, char **masque, int vies) {
    INDICE indice;
    int taille = size(sol), i_lig, i_col, code;
    char val_entree, emplacement[2] = "", **grille_jeu = creer_masque(taille); // modifier forme emplacement
    actualiser_grille_jeu(sol, masque, grille_jeu);

    printf("Entrer l'emplacement (indices ligne et colonne) et la valeur sous la forme : lignecolonne valeur\n");
    while (vies > 0 && grille_completee(grille_jeu) == false) {
        afficher_grille(grille_jeu);

        do {
            printf("empl et val=");
            scanf("%2s %c", emplacement, &val_entree);
            i_lig = (int) (emplacement[0] - '1'), i_col = (int) (emplacement[1] - 'A');
        } while ('1' + taille - 1 < emplacement[0] || emplacement[0] < '1' // ligne
                 || 'A' + taille - 1 < emplacement[1] || emplacement[1] < 'A' // colonne
                 || val_entree != '0' && val_entree != '1'
                 || masque[i_lig][i_col] == '1'); // valeur déjà affichée

        code = grille_correcte(grille_jeu);
        if (code == 1) {
            if (sol[i_lig][i_col] == val_entree) {
                printf("Coup valide et correct !\n");
                grille_jeu[i_lig][i_col] = sol[i_lig][i_col];
            } else { printf("Coup valide mais incorrect.\n"); }
        } else {
            printf("Coup invalide... Il vous reste %d vie(s).\n", --vies);
            if (code == -1) {
                printf("Il doit y avoir autant de 0 que de 1 dans les lignes et les colonnes de la grille.\n");
            } else if (code == -2) { printf("Il ne doit pas y avoir plus de 2 chiffres identiques côte à côte.\n"); }
            else { printf("2 lignes ou 2 colonnes ne peuvent être identiques.\n"); } // code -3
            printf("\n");

            donner_indice(&indice, grille_jeu);
            afficher_indice(sol, indice);
        }
    }

    afficher_grille(grille_jeu);
    if (vies == 0) {
        printf("Vous avez perdu ! Il ne vous reste plus de vies.\n");
    } else { printf("Vous avez gagné !\n"); }
}
