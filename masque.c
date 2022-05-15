
#include "masque.h"

char **creer_mat(int taille) {
    char **masque = (char **) calloc(taille, sizeof(char *));
    for (int i = 0; i < taille; i++) {
        masque[i] = (char *) calloc((taille + 1), sizeof(char));
    }
    return masque;
}

char **masque_manuel(int taille) {
    char **masque = creer_mat(taille);
    char *ligne_masque = (char *) calloc(taille + 1, sizeof(char));
    bool ligne_est_binaire;
    int j;

    printf("Entrer les lignes du masque\n");
    for (int i = 0; i < taille; i++) {
        do {
            printf("masque[%d]=", i);
            scanf("%s", ligne_masque);
            ligne_est_binaire = true;
            j = -1;

            while (ligne_est_binaire == true && ++j < strlen(ligne_masque)) {
                if (ligne_masque[j] != '1' && ligne_masque[j] != '0') ligne_est_binaire = false;
            }

        } while (strlen(ligne_masque) != taille || ligne_est_binaire == false);
        strcpy(masque[i], ligne_masque);
    }

    free(ligne_masque);
    ligne_masque = NULL;
    return masque;
}

char **masque_aleatoire(int taille) {
    char **masque = creer_mat(taille);
    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            masque[i][j] = (char) ('0' + rand() % 2);
        }
    }
    return masque;
}