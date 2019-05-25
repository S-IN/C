/* ========================================================================== */
/* Projet : "chaines" : exercice 5                                            */
/* -------------------------------------------------------------------------- */
/* Placer une sous chaine dans une chaine                                     */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char chaine[81];       /* Chaine a modifier              */
    char sousChaine[81];   /* Sous chaine a inserer          */
    int pos;               /* Position de l'insertion        */

    char ligne[81];        /* Ligne pour la saisie numerique */
    int i;

    int longueurChaine;
    int longueurSousChaine;
    int posFinSousChaine;

/* -------------------------------------------------------------------------- */
/* Saisie de chaine                                                           */
/* -------------------------------------------------------------------------- */
    printf("Entrer une chaine (max 80 caracteres) :\n");
    gets(chaine);
    longueurChaine = strlen(chaine);

/* -------------------------------------------------------------------------- */
/* Saisie de sousChaine                                                       */
/* -------------------------------------------------------------------------- */
    printf("\nEntrer une sous chaine a inserer (max 80 caracteres) :\n");
    gets(sousChaine);
    longueurSousChaine = strlen(sousChaine);

/* -------------------------------------------------------------------------- */
/* Saisie de pos                                                              */
/* -------------------------------------------------------------------------- */
    printf("\nEntrer la position d'insertion (entier) :\n");
    gets(ligne);
    pos = atoi(ligne);

/* -------------------------------------------------------------------------- */
/* Position de la fin de la sous chaine                                       */
/* -------------------------------------------------------------------------- */
    posFinSousChaine = pos + longueurSousChaine;

/* -------------------------------------------------------------------------- */
/* Si la position de la fin de la sous-chaine est au dela de la chaine, il    */
/* faut completer la chaine par des blancs et ajouter le zero final.          */
/* Il serait possible de ne pas mettre de blanc la ou va se mettre la         */
/* sous-chaine, mais il est possible que la sous-chaine debute au dela de la  */
/* fin de la chaine...                                                        */
/* -------------------------------------------------------------------------- */
    if (longueurChaine < posFinSousChaine)
    {
        for (i = longueurChaine; i < posFinSousChaine; i++)
        {
            chaine[i] = ' ';
        }
        chaine[i] = 0;
    }

/* -------------------------------------------------------------------------- */
/* Placement de la sous chaine                                                */
/* -------------------------------------------------------------------------- */
    memcpy(chaine + pos, sousChaine, longueurSousChaine);

/* -------------------------------------------------------------------------- */
/* Affichage du resultat                                                      */
/* -------------------------------------------------------------------------- */
    printf("\n\nChaine finale :\n");
    puts(chaine);

    return 0;
}
