#include "menu.h"

int m4[4][4] = {0, 0, 1, 1,
                0, 1, 1, 0,
                1, 0, 0, 1,
                1, 1, 0, 0};

int m8[8][8] = {0, 0, 0, 0, 1, 1, 1, 1,
                0, 0, 1, 1, 1, 1, 0, 0,
                0, 1, 0, 0, 1, 0, 1, 1,
                0, 1, 1, 1, 1, 0, 0, 0,
                1, 0, 0, 0, 0, 1, 1, 1,
                1, 0, 1, 1, 0, 1, 0, 0,
                1, 1, 0, 0, 0, 0, 1, 1,
                1, 1, 1, 0, 0, 0, 0, 1};

void menu() {
    int choix;
    printf("1- Saisir manuellement un masque\n"
           "2- Générer automatiquement un masque\n"
           "3- Jouer\n"
           "Choisir l'entier correspondant.");
    scanf("%d", &choix);
    // code
}
