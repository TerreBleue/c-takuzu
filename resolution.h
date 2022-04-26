#ifndef PROJET_TAKUZU_RESOLUTION_H
#define PROJET_TAKUZU_RESOLUTION_H

/* Règles de résolution :
 * règle ligne = règle colonne
 *
 * 0X0 => X=1
 * 1X1 => X=0
 * X00X => X=1
 * X11X => X=0
 * il y a le bon nombre de 1, il reste une inconnue X => X=0
 * il y a le bon nombre de 0, il reste une inconnue X => X=1
 * (exemple : X101 => X=0)
 *
 * il reste deux X et le reste correspond à une autre ligne => on prend ladite ligne en inversant là où on cherche
 * (exemple : 10101010 et 101010XY => X=0 et Y=1)
 *
 * Grille 8x8 :
 * quatre X de suite et trois 1 => les X extérieurs sont 0
 * quatre X de suite et trois 0 => les X extérieurs sont 1
 * (exemple : 1XXXX101 => XXXX = 0XX0)
 * trois X de suite, trois 1 et un 0 adjacent aux inconnues => le X le plus loin de ce 0 est 0
 * trois X de suite, trois 0 et un 1 adjacent aux inconnues => le X le plus loin de ce 1 est 1
 * (exemple : 10XXY101 => Y=0)
 */

#endif //PROJET_TAKUZU_RESOLUTION_H
