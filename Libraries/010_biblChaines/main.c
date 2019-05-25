/* ========================================================================== */
/* Test de la bibliotheque des fonctions                                      */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "chaines.h"

int main()
{
    char ligne[81];        /* Ligne de saisie                                  */

    int pc;                /* Indice du premier caractere non blanc            */
    int dc;                /* Indice du dernier caractere non blanc            */
    int retour;            /* Code retour de pcdc()                            */
    char chaine[81];       /* Chaine a modifier pour placeSousChaine()         */
    char sousChaine[81];   /* Sous chaine a inserer                            */
    int pos;               /* Position de l'insertion                          */

/* -------------------------------------------------------------------------- */
/* Saisie de ligne                                                            */
/* -------------------------------------------------------------------------- */
    printf("Entrer une ligne (maximum 80 caracteres) : ");
    gets(ligne);

/* -------------------------------------------------------------------------- */
/* Affichage du nombre de 'e'                                                 */
/* -------------------------------------------------------------------------- */
    printf("\nNombre de 'e' : %d.\n", compteLettres(ligne, 'e'));
    getchar();

/* -------------------------------------------------------------------------- */
/* Enlevement des 'e'                                                         */
/* -------------------------------------------------------------------------- */
    enleveLettres(ligne, 'e');
    puts(ligne);
    getchar();

/* -------------------------------------------------------------------------- */
/* Inversion de la chaine restante                                            */
/* -------------------------------------------------------------------------- */
    inverse(ligne);
    puts(ligne);
    getchar();

/* -------------------------------------------------------------------------- */
/* Position du premier et du dernier caractere non blanc                      */
/* -------------------------------------------------------------------------- */
    retour = pcdc(ligne, &pc, &dc);

/* -------------------------------------------------------------------------- */
/* Chaine vide                                                                */
/* -------------------------------------------------------------------------- */
    if (retour == 1)
    {
        printf("La chaine saisie est vide !\n");
    }
    else
    {
        if (retour == 2)
        {
            printf("La chaine saisie est entierement a blanc !\n");
        }
        else
        {
            printf("Premier caractere : %d\n", pc);
            printf("Dernier caractere : %d\n", dc);
            printf("Longueur : %d\n", dc - pc + 1);
        }
    }
    getchar();

/* -------------------------------------------------------------------------- */
/* Initialisation de chaine (chaine a modifier dans placeSousChaine)          */
/* -------------------------------------------------------------------------- */
    strcpy(chaine, ligne);

/* -------------------------------------------------------------------------- */
/* Saisie de sousChaine (a inserer dans ligne)                                */
/* -------------------------------------------------------------------------- */
    printf("Entrer une sous chaine a inserer (max 80 caracteres) : ");
    gets(sousChaine);

/* -------------------------------------------------------------------------- */
/* Saisie de pos                                                              */
/* -------------------------------------------------------------------------- */
    printf("Entrer la position d'insertion (entier) : ");
    gets(ligne);
    pos = atoi(ligne);

/* -------------------------------------------------------------------------- */
/* Insertion de la sous chaine                                                */
/* -------------------------------------------------------------------------- */
    placeSousChaine(chaine, sousChaine, pos, 'd');

/* -------------------------------------------------------------------------- */
/* Affichage du resultat                                                      */
/* -------------------------------------------------------------------------- */
    printf("\nChaine finale : ");
    puts(chaine);

    return 0;
}
