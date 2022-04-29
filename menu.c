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
    int choix = -1, ** sol = static_to_dynamic(m4, SIZE);
    char** masque = NULL;
    while (choix != 0) {
        printf("0- Quitter le menu\n"
               "1- Saisir manuellement un masque\n"
               "2- Générer automatiquement un masque\n"
               "3- Jouer\n"
               "Choisir l'entier correspondant.\n");
        do scanf("%d", &choix); while (choix < -1 || choix > 4);

        switch (choix) {
            case 1:
                masque = masque_manuel(SIZE);
                afficher_grille_masque(sol, masque);
                release_masque(&masque);
                break;
            case 2:
                masque = masque_aleatoire(SIZE);
                afficher_grille_masque(sol, masque);
                release_masque(&masque);
                break;
            case 3:
                masque = masque_aleatoire(SIZE);
                jouer(sol, masque, VIES);
                release_masque(&masque);
            default:
                break;
        }
    }

    release_mat(&sol, SIZE);
}
