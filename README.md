Takuzu 
=== 
Liste des programmes
---
- main.c : programme principal. En pratique, il suffit d'exécuter ce programme.

Autres fichiers :
- functions.c / functions.h : programme comportant des fonctions utiles à d'autres
- masque.c / masque.h : programme qui gère la création et l'initialisation des masques
- generation.c / generation.h : programme de génération automatique de la grille solution
- indice.c / indice.h : programme des indices / aides
- menu.c / menu.h : programme du menu

- jeu.c / jeu.h : programme du jeu de Takuzu (dont vous pourrez y jouer !)
- resolution.c / resolution.h : programme de résolution automatique d'une grille jeu

Comment utiliser le projet ?
---
- Compiler l'ensemble du projet.
- Exécuter main.c
- Vous arriverez devant un menu qui se boucle à chaque fin d'action.
    - Pour avancer dans le menu, entrez la valeur demandée dans la console.
        - Par exemple, s'il vous est demandé d'entrer un nombre pair supérieur à 2, saisissez votre nombre qui satisfait ces conditions et appuyez sur Entrée.
    - Remarque : il est déconseillé d'entrer une taille plus grande que 9.
    - Pour fermer le menu, entrez '0' après avoir saisi la taille.

- Si vous jouez au jeu, pour entrer une action : entrez l'emplacement (le numéro de ligne et la lettre majuscule de la colonne) de la case sans espace entre les caractères, puis le nombre binaire.
    - Exemple : pour entrer un '0' à la ligne 2 et à la colonne C, entrez "2C 0".
    - Astuce : si vous êtes bloqué, n'hésitez pas à entrer une valeur correcte mais peut-être invalide, vous ne serez pas pénalisé.

- Si vous faites résoudre une grille automatiquement, vous n'avez plus rien à faire jusqu'à la fin de la résolution.
    - Le programme s'interrompt systématiquement à chaque action ; cela est normal, c'est pour vous permettre de tout lire progressivement.
