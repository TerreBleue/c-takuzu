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

bool comparer_lig_prec(int code, int i, char **grille) {
    if (i == 0) return true;
    int taille = size(grille);
    int code_prec;

    for (int j = 0; j < i; ++j) { // parcourt les lignes avant grille[i]
        code_prec = 0;
        for (int k = 0; k < taille; ++k) {
            code_prec += (int) ((grille[j][k] - '0') * pow(2, k));
        }
        if (code_prec == code) return false;
    }
    return true;
}

void generer_grille(char **grille, int taille) {
    int *tab_code = (int *) calloc(taille, sizeof(int));
    int code_lig, code_prec;
    grille = creer_masque(taille);

    /*for (int i = 0; i < taille; ++i) {
        code_prec = 0;
        for (int j = 0; j < i; ++j) {
            code_prec += (int) ((grille[i][j] - '0') * pow(2, j));
        }
        do {
            code_lig = rand() % ((int) (pow(2, taille) - 1) - code_prec) + code_prec;
            for (int j = 0; j < taille; ++j) {
                tab_code[j] = code_lig % 2;
                code_lig /= 2;
            }
        } while (verif_code(code_lig, tab_code,i+1) == false);
        for (int j = i; j < taille; ++j) grille[i][j] = (char) (tab_code[j] + '0');

        code_prec = 0;
        for (int j = 0; j < i; ++j) {
            code_prec += (int) ((grille[j][i] - '0') * pow(2, j));
        }
        do {
            code_col = rand() % ((int) (pow(2, taille) - 1) - code_prec) + code_prec;
            for (int j = 0; j < taille; ++j) {
                tab_code[j] = code_col % 2;
                code_col /= 2;
            }
        } while (verif_code(code_col, tab_code,i+1) == false);
        for (int j = i; j < taille; ++j) grille[j][i] = (char) (tab_code[j] + '0');
    }*/

    do {
        for (int i = 0; i < taille; ++i) { // génération lignes
            do {
                code_lig = rand() % (int) (pow(2, taille) - 1);
                for (int j = 0; j < taille; ++j) {
                    tab_code[j] = code_lig % 2;
                    code_lig /= 2;
                }
                code_prec = 0;
                for (int j = 0; j < i; ++j) {
                    code_prec += (int) ((grille[i][j] - '0') * pow(2, j));
                }
            } while (verif_code(code_lig, tab_code, i + 1) == false || comparer_lig_prec(code_lig, i, grille) == false);
        }
    } while (grille_correcte(grille) < 0);
}
