#include "resolution.h"


int valider_coup(char **grille, char **sol, int i, int j, char valeur, int *vies) {
    if (grille[i][j] != INCONNUE) {
        printf("Cette case a déjà été remplie.\n");
        return -4;
    }

    int code, resultat;
    code = grille_correcte(grille);
    if (code == 1) {
        if (sol[i][j] == valeur) {
            printf("Coup valide et correct !\n");
            grille[i][j] = sol[i][j];
            resultat = 1;
        } else {
            printf("Coup valide mais incorrect.\n");
            resultat = 0;
        }
    } else {
        resultat = -1;
        printf("Coup invalide... Il vous reste %d vie(s).\n", --(*vies));
        if (code == -1) {
            printf("Il doit y avoir autant de 0 que de 1 dans les lignes et les colonnes de la grille.\n");
        } else if (code == -2) { printf("Il ne doit pas y avoir plus de 2 chiffres identiques côte à côte.\n"); }
        else { printf("2 lignes ou 2 colonnes ne peuvent être identiques.\n"); } // code -3
        printf("\n");
    }

    afficher_grille(grille);
    return resultat;
}

void entree_auto_securisee(char **grille, char **sol, int i, int j, char valeur, int *vies) {
    int res;
    res = valider_coup(grille, sol, i, j, valeur, vies);
    pause();
    if (res == 1) { return; }
    else if (res == 0) {
        valeur = inv_bool(valeur);
        printf("empl et val=%d%c %c\n", i + 1, j + 'A', valeur);
        printf("La valeur précédente est valide mais incorrecte ; on essaie alors son inverse.\n");
        valider_coup(grille, sol, i, j, valeur, vies);
        pause();
    } else { printf("il y a une erreur !!!"); }
}

void entree_indice_23(char **grille, INDICE indice, char *val_entree, int *i_hint) {
    int temp = *i_hint;
    if (indice.code == 2) {
        while (grille[indice.val_principale][temp] != INCONNUE) temp++;
        *val_entree = inv_bool(grille[indice.val_secondaire][temp]);
    } else if (indice.code == 3) {
        while (grille[temp][indice.val_principale] != INCONNUE) temp++;
        *val_entree = inv_bool(grille[temp][indice.val_secondaire]);
    } else {
        printf("le code ne correspond pas !!!");
        return;
    }

    *i_hint = temp;
}

void inputs_indices_23(char **grille, char **sol, INDICE indice, int *i_lig, int *i_col, char *val_entree, int *i_hint,
                       int *vies) {
    if (indice.code == 2) {
        *i_lig = indice.val_principale;

        entree_indice_23(grille, indice, val_entree, i_hint);
        printf("empl et val=%d%c %c\n", *i_lig + 1, *i_hint + 'A', *val_entree);
        afficher_indice(sol, indice);
        entree_auto_securisee(grille, sol, *i_lig, *i_hint, *val_entree, vies);

        entree_indice_23(grille, indice, val_entree, i_hint);
        *i_col = *i_hint;
    } else if (indice.code == 3) {
        *i_col = indice.val_principale;

        entree_indice_23(grille, indice, val_entree, i_hint);
        printf("empl et val=%d%c %c\n", *i_hint + 1, *i_col + 'A', *val_entree);
        afficher_indice(sol, indice);
        entree_auto_securisee(grille, sol, *i_hint, *i_col, *val_entree, vies);

        entree_indice_23(grille, indice, val_entree, i_hint);
        *i_lig = *i_hint;
    } else {
        printf("le code ne correspond pas !!!");
        return;
    }
}


void resoudre_grille(char **sol, char **masque, int vies) {
    INDICE indice;
    int taille = size(sol), i_lig, i_col, i_hint;
    char val_entree, **grille = creer_masque(taille);
    actualiser_grille_jeu(sol, masque, grille);

    printf("Entrer l'emplacement (indices ligne et colonne) et la valeur sous la forme : lignecolonne valeur\n");
    afficher_grille(grille);
    while (vies > 0 && grille_completee(grille) == false) {
        donner_indice(&indice, grille);
        if (indice.code == 0 || indice.code == 1) {
            i_lig = indice.val_principale;
            i_col = indice.val_secondaire;
            val_entree = indice.nombre_binaire;
        } else if (indice.code == 2 || indice.code == 3) {
            i_hint = 0;
            inputs_indices_23(grille, sol, indice, &i_lig, &i_col, &val_entree, &i_hint, &vies);
        } else { // res -1
            do {
                i_lig = rand() % taille, i_col = rand() % taille;
            } while (grille[i_lig][i_col] != INCONNUE);

            // on teste la validité du coup aléatoire
            grille[i_lig][i_col] = (char) ('0' + rand() % 2);
            if (grille_correcte(grille) == 1) { val_entree = grille[i_lig][i_col]; }
            else { val_entree = inv_bool(grille[i_lig][i_col]); }
            grille[i_lig][i_col] = INCONNUE;
        }

        printf("empl et val=%d%c %c\n", i_lig + 1, i_col + 'A', val_entree);
        if (indice.code != -1) { afficher_indice(sol, indice); }
        else { printf("Indice introuvable, une valeur valide arbitraire a été choisie.\n"); }
        entree_auto_securisee(grille, sol, i_lig, i_col, val_entree, &vies);
    }

    afficher_grille(grille);
    if (vies == 0) {
        printf("Vous avez perdu ! Il ne vous reste plus de vies.\n");
    } else { printf("Vous avez gagné !\n"); }
}
