/* ========================================================================== */
/* Projet : tablEx3                                                           */
/* -------------------------------------------------------------------------- */
/* Tableau à une dimension                                                    */
/* Dire si une valeur est presente dans un tableau trie en ordre croissant    */
/* ========================================================================== */

#include <stdio.h>

int main()
{
    int tableau[10] = {1, 3, 5, 7, 8, 14, 23, 33, 45, 112};  /* Tableau trie   */
    int i;                    /* Indice de parcours du tableau                 */
    int valeur;               /* Valeur a cherche dans le tableau              */

/* -------------------------------------------------------------------------- */
/* Saisie de la valeur                                                        */
/* -------------------------------------------------------------------------- */
    printf("Entrez la valeur a chercher : ");
    scanf("%d", &valeur);

/* -------------------------------------------------------------------------- */
/* Boucle de recherche : la boucle s'arrete                                   */
/*    si la valeur est supérieur à celle du tableau à l'indice i              */
/* ou si l'indice atteint la valeur i = 10                                    */
/* -------------------------------------------------------------------------- */
    i = 0;

    while((tableau[i] < valeur) && (i < 10))
    {
        i++;
    }

    printf("\nIndice final : %d\n", i);

    if ((i < 10) && (tableau[i] == valeur))
    {
        printf("\n\nLa valeur %d est trouvee dans le tableau\n\n", valeur);
    }
    else
    {
        printf("\n\nLa valeur %d n'est pas trouvee dans le tableau\n\n", valeur);
    }

    return 0;
}
