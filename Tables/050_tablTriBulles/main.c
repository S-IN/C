/* ========================================================================== */
/* Projet : tabTriBulles                                                      */
/* -------------------------------------------------------------------------- */
/* Tri d'un tableau par l'algorithme du tri a bulles                          */
/* ========================================================================== */

#include <stdio.h>

int main()
{
    int tab[8] = {5, 15, 10, 12, 3, 1, 6, 2};

    int i;
    int npermut;               /* Nombre de permutations effectuees au cours  */
                               /* d'un parcours de la table.                  */
                               /* On initialise npermut a 0 au debut de       */
                               /* chaque parcours. Si a la fin du parcours    */
                               /* npermut == 0, la table est triee            */

    int permut;                /* Variable intermediaire de permutation de    */
                               /* deux postes                                 */

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
/* i est le numero du poste que l'on compare au suivant (i + 1). Ce numero    */
/* varie donc de 0 a 6                                                        */
/* -------------------------------------------------------------------------- */
    do
    {
        npermut = 0;

        for (i = 0; i <= 6; i++)
        {
            if (tab[i] > tab[i + 1])
            {
                permut = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = permut;
                npermut++;
            }
        }
    }
    while (npermut != 0);

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
