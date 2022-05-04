#ifndef PROJET_TAKUZU_UNICITE_H
#define PROJET_TAKUZU_UNICITE_H
#include "functions.h"
#include "resolution.h"

int modifier_derniere_valeur(char **modifs, char *str);
int ecrire_modif(char **modifs, char **grille, int code, int i1, int i2, char input);
int unicite_solution(char** sol, char** masque, char** grille) {
    if (grille_completee(grille) == true) {
        return grille_correcte(grille);
    }
    // TODO unicité de la solution
    return 1;
}

#endif //PROJET_TAKUZU_UNICITE_H
