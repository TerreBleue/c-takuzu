#include "generation.h"

/**
 * Remet chaque valeur de la matrice à INCONNUE.
 * @param grille La grille à modifier
 * @param taille La taille de la grille
 * @return Rien, car elle modifie et ne crée rien.
 */
void reinit_grille(char **grille, int taille) {
    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            grille[i][j] = INCONNUE;
        }
    }
}

/**
 * Regarde la validité du code décimal et de son tableau.
 * @param code Le code décimal
 * @param tab_code Le nombre binaire du code en tableau
 * @param taille La taille du tableau
 * @return true si valides, sinon false
 */
bool verif_code(int code, const int *tab_code, int taille) {
    if (code < 0 || code > pow(2, taille) - 1) return false;

    int somme = 0, suite = 1;
    int val_suite = tab_code[0];

    if (taille % 2 == 0) {
        for (int i = 0; i < taille; ++i) somme += tab_code[i];
        if (somme != taille / 2) return false; // mauvais nombre de 0 et de 1
    }

    for (int i = 0; i < taille; ++i) {
        if (val_suite != tab_code[i]) {
            suite = 1;
            val_suite = tab_code[i];
        } else { suite++; }

        if (suite > 2) return false; // suite de trois 0 ou 1
    }

    return true;
}

/**
 * Compare une ligne aux autres.
 * @param i L'indice de la ligne comparée
 * @param grille La grille
 * @return true si elle est unique, sinon false
 */
bool lig_unique(int i, char **grille) {
    int taille = size(grille);
    for (int j = 0; j < taille; ++j) {
        if (i == j) continue;
        if (strcmp(grille[j], grille[i]) == 0) return false;
    }
    return true;
}

/**
 * Génère une ligne. \n
 * La fonction ne protège pas contre l'invalidité de la ligne obtenue / son unicité, il faut utiliser ligne_correcte.
 * @param taille La taille de la grille
 * @param grille La grille
 * @param i L'indice de la ligne
 * @param tab_code Le tableau binaire préalablement alloué
 * @param code_lig Le code décimal
 * @return Rien, elle ne fait que modifier
 */
void generation_ligne(int taille, char **grille, int i, int *tab_code, int *code_lig) {
    *code_lig = rand() % (int) pow(2, taille);
    int temp = *code_lig;
    for (int j = 0; j < taille; ++j) {
        tab_code[j] = temp % 2; // division successives
        temp /= 2;
        grille[i][j] = (char) (tab_code[j] + '0');
    }
}

/**
 * Cela vérifie si le code est correct, si le tableau binaire l'est aussi, et si la ligne est unique.
 * @param taille La taille de la grille
 * @param grille La grille
 * @param i L'indice de la ligne
 * @param tab_code Le tableau binaire préalablement alloué
 * @param code_lig Le code décimal
 * @return Un booléen indiquant la validité de la ligne (true si correct, sinon false).
 */
bool ligne_correcte(int taille, char **grille, int i, int *tab_code, int code_lig) {
    if (verif_code(code_lig, tab_code, taille) == false || lig_unique(i, grille) == false) return false;
    return true;
}

/**
 * Génère toutes les lignes de la grille, qui sont toutes correctes.\n
 * Cela ne vérifie pas si les colonnes sont elles-mêmes correctes.
 * @param taille La taille de la grille
 * @param grille La grille
 * @param tab_code Le tableau décimal préalablement alloué
 * @return Rien, cela ne fait que modifier
 */
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
    char **grille = creer_mat(taille);
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
    char **grille = creer_mat(taille);
    int code_lig;

    printf("L'objectif est de créer une grille correcte de taille %d.\n", taille);
    pause();

    do {
        generation_ligne(taille, grille, 0, tab_code, &code_lig);
    } while (ligne_correcte(taille, grille, 0, tab_code, code_lig) == false);
    printf("Voici la première ligne obtenue: %s\n"
           "On l'a générée grâce à un code aléatoire, puis on a vérifié qu'il permettrait une ligne correcte.\n",
           grille[0]);
    pause();

    printf("Voilà les autres lignes.\n");
    for (int i = 1; i < taille; ++i) {
        do {
            generation_ligne(taille, grille, i, tab_code, &code_lig);
        } while (ligne_correcte(taille, grille, 0, tab_code, code_lig) == false);
        printf("grille[%d]=%s\n", i, grille[i]);
    }
    printf("Leur code est correct et elles sont toutes différentes.\n"
           "On vérifie ensuite que la grille obtenue soit entièrement correcte.\n");
    pause();

    printf("Si elle ne l'est pas, alors on refait la grille comme ci-dessous :");
    reinit_grille(grille, taille);
    afficher_grille(grille);
    printf("et on refait toutes les étapes de génération précisées ci-dessus.\n");
    pause();

    printf("Jusqu'à obtenir une grille qui soit correcte, comme celle qui a déjà été générée dans le menu.\n");

    free(tab_code);
    tab_code = NULL;
    free_mat(&grille);
}

void afficher_lignes_correctes(int taille) {
    int *tab_code = (int *) calloc(taille, sizeof(int));
    char *tab_code_char = (char*) calloc(taille + 1, sizeof(char));
    int code_lig, temp;
    printf("Lignes correctes :\n");

    for (int i = 0; i < pow(2, taille); ++i) {
        code_lig = i;
        temp = code_lig;
        for (int j = 0; j < taille; ++j) {
            tab_code[j] = temp % 2;
            temp /= 2;
            tab_code_char[j] = (char) (tab_code[j] + '0');
        }
        if (verif_code(code_lig, tab_code, taille) == true) printf("%s\n", tab_code_char);
    }

    free(tab_code_char), tab_code_char = NULL;
    free(tab_code), tab_code = NULL;
}
