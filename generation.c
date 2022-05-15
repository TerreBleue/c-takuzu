#include "generation.h"


void reinit_grille(char **grille, int taille) {
    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            grille[i][j] = INCONNUE;
        }
    }
}

bool verif_code(int code, const int *tab_code, int taille) {
    if (code < 0 || code > pow(2, taille) - 1) return false;

    int sum = 0, suite = 1;
    int val_suite = tab_code[0];

    if (taille % 2 == 0) {
        for (int i = 0; i < taille; ++i) sum += tab_code[i];
        if (sum != taille / 2) return false;
    }

    for (int i = 0; i < taille; ++i) {
        if (val_suite != tab_code[i]) {
            suite = 1;
            val_suite = tab_code[i];
        } else { suite++; }

        if (suite > 2) return false;
    }

    return true;
}

bool comparer_lig(int i, char **grille) {
    int taille = size(grille);
    for (int j = 0; j < taille; ++j) {
        if (i == j) continue;
        if (strcmp(grille[j], grille[i]) == 0) return false;
    }
    return true;
}

void generation_ligne(int taille, char **grille, int i, int *tab_code, int *code_lig) {
    *code_lig = rand() % (int) pow(2, taille);
    int temp = *code_lig;
    for (int j = 0; j < taille; ++j) {
        tab_code[j] = temp % 2;
        temp /= 2;
        grille[i][j] = (char) (tab_code[j] + '0');
    }
}

bool ligne_correcte(int taille, char **grille, int i, int *tab_code, int code_lig) {
    if (verif_code(code_lig, tab_code, taille) == false || comparer_lig(i, grille) == false) return false;
    return true;
}

void generation_lignes_correctes(int taille, char **grille, int *tab_code) {
    int code_lig;
    for (int i = 0; i < taille; ++i) {
        do {
            generation_ligne(taille, grille, i, tab_code, &code_lig);
        } while (ligne_correcte(taille, grille, i, tab_code, code_lig) == false); // refaire ligne que si incorrecte
    }
}

char **generer_grille(int taille) {
    int *tab_code = (int *) calloc(taille, sizeof(int));
    char **grille = creer_masque(taille);
    int cpt = 0;
    do {
        cpt++, reinit_grille(grille, taille);
        generation_lignes_correctes(taille, grille, tab_code);
    } while (grille_correcte(grille) < 0);

    printf("Il a fallu %d essais pour créer la grille.\n", cpt);
    free(tab_code);
    tab_code = NULL;
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
