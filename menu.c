#include "menu.h"


int menu() {
    int taille, choix = -1;

    char **masque = NULL, **sol = NULL;
    while (1) {
        printf("Caractéristiques de la nouvelle grille solution.\n"
               "(Il est déconseillé d'entrer une taille de valeur 10 ou plus.)\n"
               "Donner la taille (paire, > 2) des grilles, ");
        do {
            printf("taille=");
            scanf("%d", &taille);
        } while (taille <= 2 || taille % 2 != 0 || taille > 26);

        printf("0- Quitter le menu\n"
               "1- Saisir manuellement un masque\n"
               "2- Générer automatiquement un masque\n"
               "3- Jouer manuellement\n"
               "4- Jouer automatiquement\n"
               "5- Générer une grille de Takuzu\n"
               "Choisir l'entier correspondant.\n");
        do {
            printf("choix=");
            scanf("%d", &choix);
        } while (choix < -1 || choix > 6);

        if (choix == 0) return 0;

        printf("Génération de la grille solution...\n");
        // sol = static_to_dynamic(taille);
        sol = generer_grille(taille);
        printf("\n");
        switch (choix) {
            case 1:
                afficher_grille(sol);
                masque = masque_manuel(taille);
                printf("\n");
                afficher_grille_masque(sol, masque);

                printf("1- Quitter le menu\n"
                       "2- Jouer avec ce masque\n"
                       "3- Résoudre la grille\n"
                       "Choisir l'entier correspondant.\n");
                do {
                    printf("choix=");
                    scanf("%d", &choix);
                } while (choix < 1 || choix > 3);
                printf("\n");
                if (choix == 1) break;
                else if (choix == 2) jouer(sol, masque, VIES);
                else resoudre_grille(sol, masque, VIES);
                break;
            case 2:
                masque = masque_aleatoire(taille);
                afficher_grille_masque(sol, masque);
                break;
            case 3:
                masque = masque_aleatoire(taille);
                jouer(sol, masque, VIES);
                break;
            case 4:
                masque = masque_aleatoire(taille);
                resoudre_grille(sol, masque, VIES);
                break;
            case 5:
                printf("1- Quitter le menu\n"
                       "2- Afficher l'ensemble des lignes valides\n"
                       "3- Générer une grille de Takuzu avec étapes\n"
                       "Choisir l'entier correspondant.\n");
                do {
                    printf("choix=");
                    scanf("%d", &choix);
                } while (choix < 1 || choix > 3);
                if (choix == 2) afficher_grille(sol);
                if (choix == 3) afficher_generation(taille);
                break;
            default:
                return 1;
        }
        printf("\n");

        if (masque != NULL) release_mat(&masque);
        release_mat(&sol);
    }

}
