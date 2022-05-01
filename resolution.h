#ifndef PROJET_TAKUZU_RESOLUTION_H
#define PROJET_TAKUZU_RESOLUTION_H
#import "functions.h"
#import "jeu.h"


bool teste_valeur_valide(char** grille, );
int modifier_derniere_valeur(char **modifs, char *str);

// allouer au préalable modifs de taille taille * taille
char **resoudre_grille(char **sol, char **masque, char **grille, char **modifs) {
    if (grille_completee(masque)) {
        if (grille_correcte(grille) == false) return; // TODO
        return modifs;
    }
    int taille = size(sol), res, i_lig, i_col;
    char val_entree, valeur_modif[4] = "", **grille_jeu = creer_masque(taille);
    int i_hint, i_hint2;

    while (grille_completee(masque) == false) { // jeu
        actualiser_grille_jeu(sol, masque, grille_jeu);
        afficher_grille(grille_jeu);

        do {
            res = donner_indice(grille_jeu, sol, &i_hint, &i_hint2, &val_entree);
            if (res != -1) afficher_indice(sol, res, i_hint, i_hint2, val_entree);
            switch (res) {
                case 0:
                    valeur_modif[0] = 'i';
                    valeur_modif[1] = i_hint + '1';
                    valeur_modif[2] = i_hint2 + 'A';
                    valeur_modif[3] = val_entree;
                    modifs[obtenir_indice_derniere_valeur(modifs) + 1] = valeur_modif;
                case 1:
                    valeur_modif[0] = 'i';
                    valeur_modif[1] = i_hint + '1';
                    valeur_modif[2] = i_hint2 + 'A';
                    valeur_modif[3] = val_entree;
                    modifs[obtenir_indice_derniere_valeur(modifs) + 1] = valeur_modif;
                case 2: // TODO entrer 1 par 1
                    strncpy(grille_jeu[i_hint], sol[i_hint], taille);
                    break;
                case 3:
                    for (int i = 0; i < taille; ++i) grille_jeu[i][i_hint] = sol[i][i_hint];
                    break;
                default:
                    break;
            }

            do {
                i_lig = rand() % taille, i_col = rand() % taille;
            } while (grille_jeu[i_lig][i_col] != INCONNUE);
            valeur_modif[0] = 'r';
            valeur_modif[1] = i_lig + '1';
            valeur_modif[2] = i_col + 'A';
            valeur_modif[3] = rand() % 2 + '0';
            grille[i_lig][i_col] = valeur_modif[3];
            masque[i_lig][i_col] = '1';
            strcpy(modifs[obtenir_indice_derniere_valeur(modifs) + 1], valeur_modif);
            resoudre_grille(sol, masque, grille, modifs);
        }
    }
}

void afficher_resolution(char **sol, char **masque, int vies) {
    int taille = size(sol), res, i_lig, i_col;
    char val_entree, emplacement[2] = "", **grille_jeu = creer_masque(taille);
    int i_hint, i_hint2;

    while (vies > 0 && grille_completee(masque) == false) { // jeu
        actualiser_grille_jeu(sol, masque, grille_jeu);
        afficher_grille(grille_jeu);


        do {
            printf("empl et val=");
            res = donner_indice(grille_jeu, sol, &i_hint, &i_hint2, &val_entree);
            if (res != -1) afficher_indice(sol, res, i_hint, i_hint2, val_entree);
            switch (res) {
                case 2: // TODO entrer 1 par 1
                    strncpy(grille_jeu[i_hint], sol[i_hint], taille);
                    break;
                case 3:
                    for (int i = 0; i < taille; ++i) grille_jeu[i][i_hint] = sol[i][i_hint];
                    break;
                default:
                    break;
            }
            pause();

            if (sol[][i_col] == val_entree) { // si correct
                printf("Coup correct !\n");
                masque[i_lig][i_col] = '1';
            } else { printf("Coup incorrect... Il vous reste %d vie(s).\n", --vies); }
        } while (res != -1);

    }

    afficher_grille(grille_jeu);
    if (vies == 0) {
        printf("Vous avez perdu ! Il ne vous reste plus de vies.");
    } else { printf("Vous avez gagné !"); }
}

#endif //PROJET_TAKUZU_RESOLUTION_H
