/* ========================================================================== */
/* Projet : tablEx2                                                           */
/* -------------------------------------------------------------------------- */
/* Dire si une valeur est presente dans un tableau (version while)            */
/* ========================================================================== */

#include <stdio.h>

int main()
{
    int tableau[10] = {1, 3, 8, 5, 14, 3, 3, 5, 12, 7};      /* Tableau        */

    int i;                    /* Indice de parcours du tableau                 */
    int valeur;               /* Valeur a cherche dans le tableau              */

/* -------------------------------------------------------------------------- */
/* Saisie de la valeur                                                        */
/* -------------------------------------------------------------------------- */
    printf("Entrez la valeur a chercher : ");
    scanf("%d", &valeur);

/* -------------------------------------------------------------------------- */
/* Boucle de recherche : la boucle s'arrete                                   */
/*    si la valeur est trouvee (i < 10)                                       */
/* ou si l'indice atteint la valeur i = 10                                    */
/* -------------------------------------------------------------------------- */
    i = 0;

    while((tableau[i] != valeur) && (i < 10))
    {
        i++;
    }

    if (i < 10)
    {
        printf("\n\nLa valeur %d est trouvee dans le tableau\n\n", valeur);
    }
    else
    {
        printf("\n\nLa valeur %d n'est pas trouvee dans le tableau\n\n", valeur);
    }

    return 0;
}
