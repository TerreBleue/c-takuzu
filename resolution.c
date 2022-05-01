#include "resolution.h"

char inv_bool(char bin) {
    return bin == '1' ? '0' : '1';
}


bool valider_coup(char **grille, char **sol, int i, int j, char valeur, int *vies) {
    int code;
    INDICE indice;
    code = grille_correcte(grille);
    if (code == 1) {
        if (sol[i][j] == valeur) {
            printf("Coup valide et correct !\n");
            grille[i][j] = sol[i][j];
        } else { printf("Coup valide mais incorrect.\n"); }
        return true;
    } else {
        printf("Coup invalide... Il vous reste %d vie(s).\n", --(*vies));
        if (code == -1) {
            printf("Il doit y avoir autant de 0 que de 1 dans les lignes et les colonnes de la grille.\n");
        } else if (code == -2) { printf("Il ne doit pas y avoir plus de 2 chiffres identiques côte à côte.\n"); }
        else { printf("2 lignes ou 2 colonnes ne peuvent être identiques.\n"); } // code -3
        printf("\n");

        donner_indice(&indice, grille);
        afficher_indice(sol, indice);
        return false;
    }
}

char inputs_indices_23(char **grille, char **sol, INDICE indice, int *i_lig, int *i_col, int *i_hint, int *vies) {
    int taille = size(grille);
    char val_entree;
    if (indice.code == 2) {
        *i_lig = indice.val_principale;

        while (*i_hint < taille || grille[*i_lig][*i_hint] != INCONNUE) (*i_hint)++;
        val_entree = inv_bool(grille[indice.val_secondaire][*i_hint]);
        printf("%d%c %c\n", i_lig + 1, i_col + 'A', val_entree);
        valider_coup(grille, sol, *i_lig, *i_hint, grille[indice.val_secondaire][*i_hint], vies);
        pause();

        printf("empl et val=");
        while (*i_hint < taille || grille[*i_lig][*i_hint] != INCONNUE) (*i_hint)++;
        val_entree = inv_bool(grille[indice.val_secondaire][*i_hint]);
    } else {
        *i_col = indice.val_principale;

        while (*i_hint < taille || grille[*i_hint][*i_col] != INCONNUE) (*i_hint)++;
        val_entree = inv_bool(grille[*i_hint][indice.val_secondaire]);
        printf("%d%c %c\n", i_lig + 1, i_col + 'A', val_entree);
        valider_coup(grille, sol, *i_hint, *i_col, val_entree, vies);
        pause();

        printf("empl et val=");
        while (*i_hint < taille || grille[*i_hint][*i_col] != INCONNUE) (*i_hint)++;
        val_entree = inv_bool(grille[*i_hint][indice.val_secondaire]);
    }

    return val_entree;
}

void resoudre_grille(char **sol, char **masque, int vies) {
    INDICE indice;
    int taille = size(sol), i_lig, i_col, i_hint;
    char val_entree, **grille = creer_masque(taille);
    actualiser_grille_jeu(sol, masque, grille);

    printf("Entrer l'emplacement (indices ligne et colonne) et la valeur sous la forme : lignecolonne valeur\n");
    while (vies > 0 && grille_completee(grille) == false) {
        i_hint = 0;
        afficher_grille(grille);

        printf("empl et val=");
        donner_indice(&indice, grille);
        if (indice.code == 0 || indice.code == 1) {
            i_lig = indice.val_principale;
            i_col = indice.val_secondaire;
            val_entree = indice.nombre_binaire;
        } else if (indice.code == 2 || indice.code == 3) { // lignes ou colonnes similaires
            val_entree = inputs_indices_23(grille, sol, indice, &i_lig, &i_col, &i_hint, &vies);
        } else { // res -1
            do {
                i_lig = rand() % taille, i_col = rand() % taille;
            } while (grille[i_lig][i_col] != INCONNUE);

            // on teste la validité du coup de valeur 1
            grille[i_lig][i_col] = '1';
            if (grille_correcte(grille)) { val_entree = '1'; }
            else { val_entree = '0'; }
            grille[i_lig][i_col] = INCONNUE;
        }
        printf("%d%c %c\n", i_lig + 1, i_col + 'A', val_entree);
        if (indice.code != -1) { afficher_indice(sol, indice); }
        else { printf("Pas d'indice trouvé, le programme va entrer une valeur valide d'emplacement aléatoire.\n"); }
        valider_coup(grille, sol, i_lig, i_col, val_entree, &vies);
        pause();
    }

    afficher_grille(grille);
    if (vies == 0) {
        printf("Vous avez perdu ! Il ne vous reste plus de vies.");
    } else { printf("Vous avez gagné !"); }
}
