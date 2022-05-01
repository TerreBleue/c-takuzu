#include "menu.h"


int menu() {
    int taille, choix = -1;
    INDICE indice;

    char **masque = NULL, **sol = NULL, **grille = NULL;
    while (1) {
        printf("Donner la taille des grilles (4 ou 8), ");
        do {
            printf("taille=");
            scanf("%d", &taille);
        } while (taille != 4 && taille != 8);

        printf("0- Quitter le menu\n"
               "1- Saisir manuellement un masque\n"
               "2- Générer automatiquement un masque\n"
               "3- Jouer manuellement\n"
               "4- Jouer automatiquement\n"
               "Choisir l'entier correspondant.\n");
        do {
            printf("choix=");
            scanf("%d", &choix);
        }
        while (choix < -1 || choix > 5);

        if (choix == 0) return 0;

        sol = static_to_dynamic(taille);
        switch (choix) {
            case 1:
                afficher_grille(sol);
                masque = masque_manuel(taille);
                afficher_grille_masque(sol, masque);

                printf("1- Quitter le menu\n"
                       "2- Appliquer des indices\n"
                       "Choisir l'entier correspondant.\n");
                do {
                    printf("choix=");
                    scanf("%d", &choix);
                } while (choix < 1 || choix > 2);

                if (choix == 1) break;
                grille = creer_masque(taille);
                actualiser_grille_jeu(sol, masque, grille);
                do {
                    donner_indice(&indice, grille);
                    switch (indice.code) {
                        case 1:
                            grille[indice.val_principale][indice.val_secondaire] = sol[indice.val_principale][indice.val_secondaire];
                            break;
                        case 2:
                            strncpy(grille[indice.val_principale], sol[indice.val_principale], taille);
                            break;
                        case 3:
                            for (int i = 0; i < taille; ++i) grille[i][indice.val_principale] = sol[i][indice.val_principale];
                            break;
                        default:
                            break;
                    }
                    afficher_grille(grille);
                } while (indice.code != -1);

                break;
            case 2:
                masque = masque_aleatoire(taille);
                afficher_grille_masque(sol, masque);
                break;
            case 3:
                masque = masque_aleatoire(taille);
                jouer(sol, masque, VIES);
            case 4:
                masque = masque_aleatoire(taille);
                resoudre_grille(sol, masque, VIES);
            default:
                return 1;
        }

        release_mat(&masque);
        release_mat(&sol);
    }
}
