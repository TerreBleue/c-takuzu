#include "jeu.h"

bool grille_completee(char **grille) {
    int taille = size(grille);
    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; j++) if (grille[i][j] == INCONNUE) return false;
    }
    return true;
}

int grille_correcte(char **grille) {
    int taille = size(grille), cpt_lig_0, cpt_col_0, cpt_lig_1, cpt_col_1, cpt_sim, cpt_suite_lig, cpt_suite_col;
    char suite_lig, suite_col;
    for (int i = 0; i < taille; ++i) {
        cpt_lig_0 = 0, cpt_col_0 = 0, cpt_lig_1 = 0, cpt_col_1 = 0, cpt_sim = 0;
        cpt_suite_lig = 0, cpt_suite_col = 0;
        for (int j = 0; j < taille; ++j) {
            if (grille[i][j] == '0') cpt_lig_0++;
            if (grille[j][i] == '0') cpt_col_0++;
            if (grille[i][j] == '1') cpt_lig_1++;
            if (grille[j][i] == '1') cpt_col_1++;

            if (i != j) {
                if (strcmp(grille[i], grille[j]) == 0) return -3;
                for (int k = 0; k < taille; ++k) if (grille[k][i] == grille[k][j]) cpt_sim++;
                if (cpt_sim == taille) return -3;
            }

            if (j == 0) {
                suite_lig = grille[i][j];
                suite_col = grille[j][i];
            }
            if (suite_lig == grille[i][j]) { cpt_suite_lig++; }
            else {
                suite_lig = grille[i][j];
                cpt_suite_lig = 1;
            }

            if (suite_col == grille[j][i]) { cpt_suite_col++; }
            else {
                suite_col = grille[j][i];
                cpt_suite_col = 1;
            }

            if (suite_lig != INCONNUE && cpt_suite_lig > 2) return -2;
            if (suite_col != INCONNUE && cpt_suite_col > 2) return -2;
        }
        if (cpt_lig_0 > taille / 2 || cpt_col_0 > taille / 2
            || cpt_lig_1 > taille / 2 || cpt_col_1 > taille / 2) {
            return -1;
        }
    }

    return 1;
}

void jouer(char **sol, char **masque, int vies) {
    INDICE indice;
    int taille = size(sol), i_lig, i_col, code;
    char val_entree, emplacement[2] = "", **grille_jeu = creer_masque(taille);
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
        printf("Vous avez perdu ! Il ne vous reste plus de vies.");
    } else { printf("Vous avez gagné !"); }
}
