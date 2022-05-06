#ifndef PROJET_TAKUZU_MASQUE_H
#define PROJET_TAKUZU_MASQUE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Alloue un masque de taille donnée.
 * @param taille La taille
 * @return Un pointeur vers ce masque
 */
char** creer_masque(int taille);

/**
 * Crée un masque de taille donnée selon les entrées du joueur
 * @param taille La taille
 * @return Un pointeur de ce masque
 */
char** masque_manuel(int taille);

/**
 * Crée un masque aléatoire de taille donnée.
 * @param taille La taille
 * @return Un pointeur vers ce masque
 */
char** masque_aleatoire(int taille);

#endif //PROJET_TAKUZU_MASQUE_H
