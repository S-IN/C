/* ========================================================================== */
/* Placer une sous chaine dans une chaine                                     */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void placeSousChaine(char* chaine, char* sChaine, int pos, char sens);

int main()
{
    char chaine[81];       /* Chaine a modifier              */
    char sousChaine[81];   /* Sous chaine a inserer          */
    int pos;               /* Position de l'insertion        */

    char ligne[81];        /* Ligne pour la saisie numerique */

/* -------------------------------------------------------------------------- */
/* Saisie de chaine                                                           */
/* -------------------------------------------------------------------------- */
    printf("Entrer une chaine (max 80 caracteres) :\n");
    gets(chaine);

/* -------------------------------------------------------------------------- */
/* Saisie de sousChaine                                                       */
/* -------------------------------------------------------------------------- */
    printf("\nEntrer une sous chaine a inserer (max 80 caracteres) :\n");
    gets(sousChaine);

/* -------------------------------------------------------------------------- */
/* Saisie de pos                                                              */
/* -------------------------------------------------------------------------- */
    printf("\nEntrer la position d'insertion (entier) :\n");
    gets(ligne);
    pos = atoi(ligne);

/* -------------------------------------------------------------------------- */
/* Insertion de la sous chaine                                                */
/* -------------------------------------------------------------------------- */
    placeSousChaine(chaine, sousChaine, pos, 'd');

/* -------------------------------------------------------------------------- */
/* Affichage du resultat                                                      */
/* -------------------------------------------------------------------------- */
    printf("\n\nChaine finale :\n");
    puts(chaine);

    return 0;
}

/* ========================================================================== */
/* Placer une sous-chaine dans une chaine, a une certaine position, avec      */
/* cadrage a gauche ou a droite de la position                                */
/* -------------------------------------------------------------------------- */
/* Parametres :                                                               */
/* chaine  : chaine a remplir                                                 */
/* sChaine : sous chaine a placer danlettres chaine                                 */
/* pos     : position de la sous-chaine dans la chaine (0 : debut)            */
/* sens    : 'g' ==> la sous-chaine est placee a gauche de pos                */
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
