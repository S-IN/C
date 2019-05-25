/* ========================================================================== */
/* Projet : tabTriSE                                                          */
/* -------------------------------------------------------------------------- */
/* Tri d'un tableau par l'algorithme de selection echange                     */
/* ========================================================================== */

#include <stdio.h>

int main()
{
    int tab[8] = {5, 15, 10, 12, 3, 1, 6, 2};

    int iter;      /* Numero d'iteration (numero du poste a affecter)         */
    int pp;        /* Indice du Plus Petit poste trouve dans un parcours      */
    int i;         /* Indice de l'element courant                             */
    int permut;    /* Variable intermediaire de permutation de deux postes    */

/* -------------------------------------------------------------------------- */
/* Affichage initial du tableau                                               */
/* -------------------------------------------------------------------------- */
    printf("Tableau initial :\n\n");
    for (i = 0; i <= 7; i++)
    {
        printf("tab[%d] = %d\n", i, tab[i]);
    }

/* -------------------------------------------------------------------------- */
/* Debut de l'algorithme de tri                                               */
/* Boucle de selection echange                                                */
/* -------------------------------------------------------------------------- */
    for (iter = 0; iter <= 6; iter++)
    {
        pp = iter;

/* -------------------------------------------------------------------------- */
/* Boucle de selection : recherche du plus petit poste du tableau             */
/* -------------------------------------------------------------------------- */
        for (i = iter; i <= 7; i++)
        {
            if (tab[i] < tab[pp])
            {
                pp = i;
            }
        }

/* -------------------------------------------------------------------------- */
/* Echange                                                                    */
/* -------------------------------------------------------------------------- */
        permut = tab[iter];
        tab[iter] = tab[pp];
        tab[pp] = permut;
    }

/* -------------------------------------------------------------------------- */
/* Affichage final du tableau                                                 */
/* -------------------------------------------------------------------------- */
    printf("\n\nTableau trie :\n\n");
    for (i = 0; i <= 7; i++)
    {
        printf("tab[%d] = %d\n", i, tab[i]);
    }

    return 0;
}
