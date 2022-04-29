#include "menu.h"


void menu() {
    int choix = -1, taille;
    char** sol = static_to_dynamic(SIZE), **masque = NULL;
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
                break;
            case 2:
                masque = masque_aleatoire(SIZE);
                afficher_grille_masque(sol, masque);
                break;
            case 3:
                masque = masque_aleatoire(SIZE);
                jouer(sol, masque, VIES);

            default:
                break;
        }

        if (masque != NULL) release_mat(&masque);
    }

    release_mat(&sol);
}
