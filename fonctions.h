#ifndef PROJET_TAKUZU_FONCTIONS_H
#define PROJET_TAKUZU_FONCTIONS_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define VIES 3
#define INCONNUE '.'

/**
 * Pause 5 secondes le programme (donc l'affichage) et affiche une ligne horizontale.
 */
void pause();

/**
 * "Efface" la console.
 */
void clear();

/**
 * Inverse un nombre binaire (en char) :\n
 * * '0' devient '1' ;\n
 * * '1' devient '0'
 * @param bin Le nombre binaire en char
 * @return Son inverse
 */
char inv_bool(char bin);

/**
 * On suppose la matrice carrée. Donne sa taille (longueur/largeur).
 * @param str La matrice carrée
 * @return Sa taille
 */
int size(char **str);

/**
 * Fonction ancienne. Donne une matrice pré-générée.
 * @param taille La taille de la matrice
 * @return Un pointeur vers la matrice pré-générée
 */
char **statique_vers_dynamique(int taille);

/**
 * La solution et le masque sont donnés. Actualise la grille jeu selon les ajouts de 1 du masque.
 * @param sol Solution
 * @param masque Masque
 * @param grille_jeu Grille jeu (sera modifiée)
 * @return Rien, cela ne fait que modifier.
 */
void actualiser_grille_jeu(char **sol, char **masque, char **grille_jeu);

/**
 * Affiche une grille jeu de manière intelligente (avec les indices de lignes et de colonnes).
 * @param grille La grille jeu
 * @return Rien, cela ne fait que modifier.
 */
void afficher_grille(char **grille);

/**
 * Affiche une grille jeu de manière intelligente (avec les indices de lignes et de colonnes).\n
 * Contrairement à afficher_grille, cela utilise les grilles solution et masque.
 * @param solution Solution
 * @param masque Masque
 * @return Rien, cela ne fait que modifier.
 */
void afficher_grille_masque(char **solution, char **masque);

/**
 * Libère entièrement une matrice. \n
 * Cela met aussi son pointeur à NULL.
 * @param mat La matrice à libérer (non réversible)
 * @return Rien, cela ne fait que modifier.
 */
void free_mat(char ***mat);

/**
 * Booléen qui donne l'état de complétion de la grille jeu.
 * @param grille Grille jeu
 * @return true si complétée, false sinon
 */
bool grille_completee(char **grille);

/**
 * Renvoie un entier de signe différent selon si la grille jeu respecte les règles du Takuzu.
 * @param grille Grille jeu
 * @return 1 si elle est encore correcte (respecte les règles), sinon un entier négatif :\n
 * * -1 s'il n'y a pas autant de 0 que de 1 dans une ligne ou une colonne\n
 * * -2 s'il y a une suite de trois 0 ou 1 dans une ligne/colonne\n
 * * -3 si deux lignes ou colonnes sont égales
 */
int grille_correcte(char **grille);

#endif //PROJET_TAKUZU_FONCTIONS_H
