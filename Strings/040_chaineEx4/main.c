/* ========================================================================== */
/* Projet : "chaines" : exercice 4                                            */
/* -------------------------------------------------------------------------- */
/* Premier et dernier caractere non blanc d'une chaine                        */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>

int main()
{
    char ligne[81];
    int pc;
    int dc;
    int longueurLigne;

/* -------------------------------------------------------------------------- */
/* Saisie de ligne                                                            */
/* -------------------------------------------------------------------------- */
    printf("Entrer une ligne (max 80 caracteres) :\n");
    gets(ligne);
    longueurLigne = strlen(ligne);

/* -------------------------------------------------------------------------- */
/* Chaine vide                                                                */
/* -------------------------------------------------------------------------- */
    if (longueurLigne == 0)
    {
        printf("La chaine saisie est vide !\n");
    }
    else
    {

/* -------------------------------------------------------------------------- */
/* Recherche du premier caractere non blanc                                   */
/* -------------------------------------------------------------------------- */
        pc = 0;

        while ((ligne[pc] == ' ') && (pc < longueurLigne))
        {
            pc++;
        }

/* -------------------------------------------------------------------------- */
/* La ligne est entierement a blanc                                           */
/* -------------------------------------------------------------------------- */
        if (pc == longueurLigne)
        {
            printf("La chaine saisie est entierement a blanc !\n");
        }
        else
        {

/* -------------------------------------------------------------------------- */
/* Recherche du dernier caractere non blanc                                   */
/* -------------------------------------------------------------------------- */
            dc = longueurLigne - 1;

            while (ligne[dc] == ' ')
            {
                dc--;
            }

            printf("Premier caractere : %d\n", pc);
            printf("Dernier caractere : %d\n", dc);
        }
    }

    return 0;
}
