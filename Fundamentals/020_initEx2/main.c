/* ========================================================================== */
/* Projet : initEx2                                                           */
/* -------------------------------------------------------------------------- */
/* Afficher la liste des premiers nombres avec leur racine carree, le cumul   */
/* des racines carrees, jusqu'a ce que le cumul soit > 30                     */
/* ========================================================================== */

#include <stdio.h>
#include <math.h>

int main()
{
    int i;
    double racine, cumul;

    i = 1;
    cumul = 0;

    printf("\nNombre       Racine        Cumul\n\n");

    do
    {
        racine = sqrt(i);
        cumul += racine;
        printf("  %2d        %7.3f      %7.3f\n", i, racine, cumul);
        i++;
    }
    while (cumul < 30);

    return 0;
}
