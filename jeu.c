#include "jeu.h"


void jouer(char **sol, char **masque, int vies) {
    int taille = size(sol);
    INDICE indice;
    char **grille_jeu = creer_mat(taille);
    int entree_lig, i_lig, i_col, code;
    char entree_empl[3], *entree_col, val_entree;
    actualiser_grille_jeu(sol, masque, grille_jeu);

    printf("Entrer l'emplacement (indices ligne et colonne) et la valeur sous la forme : lignecolonne valeur\n");
    while (vies > 0 && grille_completee(grille_jeu) == false) {
        afficher_grille(grille_jeu);

        do {
            printf("ligcol et val=");
            scanf("%3s %c", entree_empl, &val_entree);
            entree_lig = strtol(entree_empl, &entree_col, 10); // début du str converti en int
            i_lig = entree_lig - 1, i_col = (int) (entree_col[0] - 'A');
        } while (i_lig < 0 || i_lig >= taille
                 || i_col < 0 || i_col >= taille
                 || val_entree != '0' && val_entree != '1'
                 || grille_jeu[i_lig][i_col] != INCONNUE); // valeur déjà affichée

        grille_jeu[i_lig][i_col] = val_entree; // test validité du coup : on met temp la grille à valeur entrée
        code = grille_correcte(grille_jeu);
        grille_jeu[i_lig][i_col] = INCONNUE;
        if (code == 1) {
            if (sol[i_lig][i_col] == val_entree) {
                printf("Coup valide et correct !\n");
                grille_jeu[i_lig][i_col] = sol[i_lig][i_col];
            } else { printf("Coup valide mais incorrect.\n"); }
        } else {
            printf("Coup invalide... Il vous reste %d vie(s).\n", --vies);
            if (code == -1) {
                printf("Il doit y avoir autant de 0 que de 1 dans les lignes et les colonnes de la grille.\n");
            } else if (code == -2) {
                printf("Il ne doit pas y avoir plus de 2 chiffres identiques côte à côte.\n");
            } else { printf("2 lignes ou 2 colonnes ne peuvent être identiques.\n"); } // code -3
            printf("\n");

            donner_indice(&indice, grille_jeu);
            afficher_indice(sol, indice);
        }
    }

    afficher_grille(grille_jeu);
    if (vies == 0) { printf("Vous avez perdu... Il ne vous reste plus de vies.\n"); }
    else { printf("Vous avez gagné !\n"); }
    printf("\n");
}
