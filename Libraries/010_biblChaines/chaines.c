/* ========================================================================== */
/* chaines.c : Bibliotheque des fonctions                                     */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>

#include "chaines.h"

/* ========================================================================== */
/* Fonction compteLettres :                                                   */
/* -------------------------------------------------------------------------- */
/* Parametres : ligne  : chaine examinee                                      */
/*              lettre : lettre cherchee                                      */
/* ========================================================================== */

int compteLettres(char* ligne, char lettre)
{
    int compteur;
    char* debut;

    compteur = 0;
    debut = strchr(ligne, lettre);

    while (debut!= 0)
    {
        compteur++;
        debut++;
        debut = strchr(debut, lettre);
    }

    return compteur;
}


/* ========================================================================== */
/* Fonction enleveLettres :                                                   */
/* -------------------------------------------------------------------------- */
/* Parametres : ligne  : chaine a traiter                                     */
/*              lettre : lettre a enlever                                     */
/* ========================================================================== */

void enleveLettres(char* ligne, char lettre)
{
    char * adresse;
    adresse = strchr(ligne, 'e');

    while (adresse != 0)
    {
        strcpy(adresse, adresse + 1);
        adresse = strchr(adresse, 'e');
    }
}



/* ========================================================================== */
/* Fonction inverse :                                                         */
/* -------------------------------------------------------------------------- */
/* Parametre : ligne  : chaine a inverser                                     */
/* ========================================================================== */

char* inverse(char* ligne)
{
    int i1;            /* Poste de gauche a inverser                           */
    int i2;            /* Poste de droite a inverser                           */
    char permut;       /* Caractere de permutation                             */

    i1 = 0;
    i2 = strlen(ligne) - 1;

    while (i1 < i2)
    {
        permut = ligne[i1];
        ligne[i1] = ligne[i2];
        ligne[i2] = permut;
        i1++;
        i2--;
    }

    return ligne;
}

/* ========================================================================== */
/* Recherche de la position du premier(pc) et du dernier(dc) caractere non    */
/* blanc d'une chaine.                                                        */
/*                                                                            */
/* Valeur retournee : 0    ==> normal                                         */
/*                    1    ==> chaine vide                                    */
/*                    2    ==> chaine entierement a blanc                     */
/* ========================================================================== */

int pcdc(char* chaine, int* pPc, int *pDc)
{
    int longChaine;
    int retour;

    retour = 0;
    longChaine = strlen(chaine);

    if (longChaine == 0)
    {
        retour = 1;
    }
    else
    {
        *pPc = 0;

        while ((chaine[*pPc] == ' ') && (*pPc < longChaine))
        {
            (*pPc)++;
        }

        if (*pPc == longChaine)
        {
            retour = 2;
        }
        else
        {
            *pDc = longChaine - 1;
            while (chaine[*pDc] == ' ')
            {
                (*pDc)--;
            }
        }
    }
    return retour;
}


/* ========================================================================== */
/* Placer une sous-chaine dans une chaine, a une certaine position, avec      */
/* cadrage a gauche ou a droite de la position                                */
/* -------------------------------------------------------------------------- */
/* Parametres :                                                               */
/* chaine  : chaine a remplir                                                 */
/* sChaine : sous chaine a placer dans chaine                                 */
/* pos     : position de la sous-chaine dans la chaine (0 : debut)            */
/* cadrage : 'g' ==> la sous-chaine est placee a gauche de pos                */
/*           'd' ==> la sous-chaine est placee a droite de pos                */
/* ========================================================================== */

void placeSousChaine(char* chaine, char* sChaine, int pos, char sens)
{
    int lChaine;
    int posFinSChaine;
    int i;

/* -------------------------------------------------------------------------- */
/* Position de la fin de la sous chaine                                       */
/* -------------------------------------------------------------------------- */
    if (sens == 'd')
    {
        posFinSChaine = pos + strlen(sChaine);
    }
    else
    {
        posFinSChaine = pos + 1;
    }

/* -------------------------------------------------------------------------- */
/* Si la position d'insertion est au dela de la fin de la chaine a remplir,   */
/* il faut completer par des blancs                                           */
/* -------------------------------------------------------------------------- */
    lChaine  = strlen(chaine);

    if (lChaine < posFinSChaine)
    {
        for (i = lChaine; i < posFinSChaine; i++)
        {
            chaine[i] = ' ';
        }
        chaine[i] = 0;
    }

/* -------------------------------------------------------------------------- */
/* Placement de la sous-chaine                                                */
/* -------------------------------------------------------------------------- */
    if (sens == 'd')
    {
        memcpy(chaine + pos, sChaine, strlen(sChaine));
    }
    else
    {
        memcpy(chaine + pos - strlen(sChaine) + 1, sChaine, strlen(sChaine));
    }
}
