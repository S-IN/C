/* ========================================================================== */
/* initEx3                                                                    */
/* -------------------------------------------------------------------------- */
/* Saisir des nombres jusqu'a ce que leur total dépasse 100                   */
/* ========================================================================== */

#include <stdio.h>

int main()
{
    int n;                     /* Sert a recevoir le nombre tape               */
    int total;                 /* Contient le total des nombres (n) deja tapes */

    printf("Nombre a ajouter : ");
    scanf("%d", &n);
    total = n;

    while (total < 100)
    {
        printf("Total actuel : %d\n", total);

        printf("\n\nNombre a ajouter : ");
        scanf("%d", &n);
        total += n;
    }

    printf("\nTotal final : %d\n", total);

    return 0;
}
