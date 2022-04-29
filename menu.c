#include "menu.h"


int menu() {
    int taille, choix = -1;
    int hint_code, n, m;
    char** masque = NULL, **sol = NULL, **grille = NULL;
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
                afficher_grille(sol);
                masque = masque_manuel(taille);
                afficher_grille_masque(sol, masque);

                printf("0- Quitter le menu\n"
                       "1- Appliquer des indices\n"
                       "Choisir l'entier correspondant.\n");
                do {
                    printf("choix=");
                    scanf("%d", &choix);
                } while (choix < -1 || choix > 2);

                if (choix == 0) break;
                grille = creer_masque(taille);
                actualiser_grille_jeu(sol, masque, grille);
                do {
                    hint_code = donner_indice(grille, &n, &m);
                    switch (hint_code) {
                        case 1:
                            grille[n][m] = sol[n][m];
                            break;
                        case 2:
                            strncpy(grille[n], sol[n], taille);
                            break;
                        case 3:
                            for (int i = 0; i < taille; ++i) grille[i][n] = sol[i][n];
                            break;
                        default:
                            break;
                    }
                } while (hint_code != -1);



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
