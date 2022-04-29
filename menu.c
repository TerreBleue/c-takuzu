#include "menu.h"


int menu() {
    int choix = -1, taille;
    char** masque = NULL, **sol = NULL;
    while (choix != 0) {
        printf("Donner la taille des grilles (4 ou 8), ");
        do {
            printf("taille=");
            scanf("%d", &taille);
        } while (taille != 4 && taille != 8);

        printf("0- Quitter le menu\n"
               "1- Saisir manuellement un masque\n"
               "2- Générer automatiquement un masque\n"
               "3- Jouer\n"
               "Choisir l'entier correspondant.\n");
        do {
            printf("choix=");
            scanf("%d", &choix);
        }
        while (choix < -1 || choix > 4);

        if (choix == 0) return 0;

        sol = static_to_dynamic(taille);
        switch (choix) {
            case 1:
                masque = masque_manuel(taille);
                afficher_grille_masque(sol, masque);
                break;
            case 2:
                masque = masque_aleatoire(taille);
                afficher_grille_masque(sol, masque);
                break;
            case 3:
                masque = masque_aleatoire(taille);
                jouer(sol, masque, VIES);

            default:
                return 1;
        }

        release_mat(&masque);
        release_mat(&sol);
    }
}
