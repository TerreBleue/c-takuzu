#include "jeu.h"


int valider_coup(char **grille, char **sol, int i_ligne, int i_colonne, char valeur, int *vies) {
    if (grille[i_ligne][i_colonne] != INCONNUE) {
        printf("Cette case a déjà été remplie.\n");
        return -4;
    }

    int code;
    grille[i_ligne][i_colonne] = valeur; // on met tempo la case à la valeur entrée
    code = grille_correcte(grille);
    grille[i_ligne][i_colonne] = INCONNUE;

    if (code == 1) {
        if (sol[i_ligne][i_colonne] == valeur) {
            printf("Coup valide et correct !\n");
            grille[i_ligne][i_colonne] = sol[i_ligne][i_colonne];
            return 1;
        }
        printf("Coup valide mais incorrect.\n");
        return 0;
    } else {
        printf("Coup invalide... Il vous reste %d vie(s).\n", --(*vies));
        if (code == -1) {
            printf("Il doit y avoir autant de 0 que de 1 dans les lignes et les colonnes de la grille.\n");
        } else if (code == -2) { printf("Il ne doit pas y avoir plus de 2 chiffres identiques côte à côte.\n"); }
        else { printf("2 lignes ou 2 colonnes ne peuvent être identiques.\n"); } // code -3
        return -1;
    }
}


void jouer(char **sol, char **masque, int vies) {
    int taille = size(sol);
    INDICE indice;
    char **grille_jeu = creer_mat(taille);
    int entree_lig, i_lig, i_col;
    char entree_empl[3], *entree_col, val_entree;
    actualiser_grille_jeu(sol, masque, grille_jeu);

    printf("Entrer l'emplacement (indices ligne et colonne) et la valeur sous la forme : lignecolonne valeur\n");
    while (vies > 0 && grille_completee(grille_jeu) == false) {
        afficher_grille(grille_jeu);

        do {
            printf("ligcol et val=");
            scanf("%3s %c", entree_empl, &val_entree);
            entree_lig = strtol(entree_empl, &entree_col, 10); // début du str converti en int, reste pointé
            i_lig = entree_lig - 1, i_col = (int) (entree_col[0] - 'A');
        } while (i_lig < 0 || i_lig >= taille
                 || i_col < 0 || i_col >= taille
                 || val_entree != '0' && val_entree != '1'
                 || grille_jeu[i_lig][i_col] != INCONNUE);

        if (valider_coup(grille_jeu, sol, i_lig, i_col, val_entree, &vies) == -1) { // invalide
            donner_indice(&indice, grille_jeu);
            afficher_indice(sol, indice);
        }
        printf("\n");
    }

    afficher_grille(grille_jeu);
    if (vies == 0) {
        return (void) printf("Vous avez perdu... Il ne vous reste plus de vies.\n"
                             "\n");
    }
    return (void) printf("Vous avez gagné !\n"
                         "\n");
}
