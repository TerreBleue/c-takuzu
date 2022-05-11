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

void generation_ligne(int taille, char **grille, int i, int *tab_code, int *code_lig) {
    *code_lig = rand() % (int) pow(2, taille);
    for (int j = 0; j < taille; ++j) {
        tab_code[j] = *code_lig % 2;
        *code_lig /= 2;
        grille[i][j] = (char) (tab_code[j] + '0');
    }
}

bool ligne_correcte(int taille, char **grille, int i, int *tab_code, int code_lig) {
    if (verif_code(code_lig, tab_code, taille) == false || comparer_lig_prec(i, grille) == false) return false;
    return true;
}

void generation_lignes_correctes(int taille, char **grille, int *tab_code) {
    int code_lig;
    for (int i = 0; i < taille; ++i) {
        do {
            generation_ligne(taille, grille, i, tab_code, &code_lig);
        } while (ligne_correcte(taille, grille, i, tab_code, code_lig) ? false : true); // refaire ligne que si incorrecte
    }
}

char **generer_grille(int taille) {
    clock_t tic = clock();
    int *tab_code = (int *) calloc(taille, sizeof(int));
    char **grille = creer_masque(taille);

    do {
        generation_lignes_correctes(taille, grille, tab_code);
    } while (grille_correcte(grille) < 0);

    free(tab_code);
    tab_code = NULL;
    clock_t toc = clock();
    printf("Temps de génération de la grille en secondes : %f\n", (toc - tic) / CLOCKS_PER_SEC);
    return grille;
}

void afficher_generation(int taille) {
    int *tab_code = (int *) calloc(taille, sizeof(int));
    char **grille = creer_masque(taille);

    printf("On génère une nouvelle grille en détaillant chaque création de grille temporaire.\n");
    do {
        generation_lignes_correctes(taille, grille, tab_code);
        afficher_grille(grille);
        pause();
    } while (grille_correcte(grille) < 0);
    printf("Cette grille est correcte, alors on s'arrête là.\n");

    free(tab_code);
    tab_code = NULL;
}
