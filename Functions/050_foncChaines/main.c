/* ========================================================================== */
/* Premier et dernier caractere non blanc d'une chaine                        */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>

int pcdc(char* chaine, int* pPc, int *pDc);

int main()
{
    char ligne[81];
    int pc;
    int dc;
    int retour;

/* -------------------------------------------------------------------------- */
/* Saisie de ligne                                                            */
/* -------------------------------------------------------------------------- */
    printf("Entrer une ligne (max 80 caracteres) :\n");
    gets(ligne);

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
            printf("\nPremier caractere : %d\n", pc);
            printf("Dernier caractere : %d\n", dc);
            printf("Longueur : %d\n", dc - pc + 1);
        }
    }

    return 0;
}

/* ========================================================================== */
/* Recherche de la position du premier(*pPc) et du dernier(*pDc) caractere    */
/* non blanc d'une chaine.                                                    */
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
