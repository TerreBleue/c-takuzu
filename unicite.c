#include "unicite.h"

int modifier_derniere_valeur(char **modifs, char *str) {
    int i = 0;
    while (modifs[i][0] != '\0') i++;
    strcpy(modifs[i], str);
    return i;
}

int ecrire_modif(char **modifs, char **grille, int code, int i1, int i2, char input) {
    int taille = size(grille), ind = 0, lig = 0, col = 0;
    char modif_temp[4];

    modif_temp[0] = 'i';
    modif_temp[3] = input;
    if (code == -1) {
        do {
            i1 = rand() % taille, i2 = rand() % taille;
        } while (grille[i1][i2] != INCONNUE);
        modif_temp[0] = 'r';
        modif_temp[1] = (char) (i1 + '1');
        modif_temp[2] = (char) (i2 + 'A');
        modif_temp[3] = rand() % 2 + '0';
        ind = modifier_derniere_valeur(modifs, modif_temp);
    } else if (code == 0 || code == 1) {
        modif_temp[1] = (char) (i1 + '1');
        modif_temp[2] = (char) (i2 + 'A');
        ind = modifier_derniere_valeur(modifs, modif_temp);
    } else if (code == 2) {
        modif_temp[1] = (char) (i1 + '1');
        for (int i = 0; i < 2; ++i) {
            while (grille[i1][col] != INCONNUE) col++;
            modif_temp[2] = (char) (col + 'A');
            modif_temp[3] = grille[i1][col] == '0' ? '1' : '0';
            ind = modifier_derniere_valeur(modifs, modif_temp);
        }
        ind--;
    } else if (code == 3) {
        modif_temp[2] = (char) (i2 + 'A');
        for (int i = 0; i < 2; ++i) {
            while (grille[lig][i1] != INCONNUE) lig++;
            modif_temp[1] = (char) (lig + '1');
            modif_temp[3] = grille[lig][i1] == '0' ? '1' : '0';
            ind = modifier_derniere_valeur(modifs, modif_temp);
        }
        ind--;
    } else {
        printf("Code non pris en charge\n");
        return -1;
    }
    return ind;
}
