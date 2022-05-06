#include "generation.h"

bool verif_code(int code, const int *tab_code, int taille) {
    if (code < 0 || code > pow(2, taille) - 1) return false;


    int sum = 0, suite = 1;
    int val_suite;
    bool code_correct = true;
    val_suite = tab_code[0];

    if (taille % 2 == 0) {
        for (int i = 0; i < taille; ++i) sum += tab_code[i];
        if (sum != taille / 2) code_correct = false;
    }

    if (code_correct == true) {
        for (int i = 0; i < taille; ++i) {
            if (val_suite != tab_code[i]) {
                suite = 1;
                val_suite = tab_code[i];
            } else { suite++; }

            if (suite > 2) code_correct = false;
        }
    }

    return code_correct;
}

bool comparer_lig_prec(int i, char **grille) {
    if (i == 0) return true;

    for (int j = 0; j < i; ++j) { // parcourt les lignes avant grille[i]
        if (strcmp(grille[j], grille[i]) == 0) return false;
    }
    return true;
}

char **generer_grille(int taille) {
    int *tab_code = (int *) calloc(taille, sizeof(int));
    int code_lig;
    char **grille = creer_masque(taille);

    do {
        for (int i = 0; i < taille; ++i) { // génération lignes
            do {
                code_lig = rand() % (int) pow(2, taille);
                for (int j = 0; j < taille; ++j) {
                    tab_code[j] = code_lig % 2;
                    code_lig /= 2;
                    grille[i][j] = (char) (tab_code[j] + '0');
                }
            } while (verif_code(code_lig, tab_code, taille) == false || comparer_lig_prec(i, grille) == false);
        }

    } while (grille_correcte(grille) < 0);

    free(tab_code);
    tab_code = NULL;
    return grille;
}
