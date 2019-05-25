/* ========================================================================== */
/* Projet : initEx1                                                           */
/* -------------------------------------------------------------------------- */
/* Afficher la liste des 10 premiers nombres avec leur racine carree et le    */
/* cumul des racines carrees                                                  */
/* ========================================================================== */

#include <stdio.h>
#include <math.h>

int main()
{
    int i;
    double racine, cumul;

    cumul = 0;

    printf("\nNombre       Racine        Cumul\n\n");

    for (i = 1; i <= 10; i++)
    {
        racine = sqrt(i);
        cumul += racine;
        printf("  %2d        %7.3f      %7.3f\n", i, racine, cumul);
    }

    return 0;
}
