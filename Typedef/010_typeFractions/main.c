/* ========================================================================== */
/* Projet : typeFractions : Fonctions - Fractions - Structures                */
/* ========================================================================== */

/* ========================================================================== */
/* DECLARATIONS                                                               */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int Num;
    int Den;
} FRACTION;

void saisie(FRACTION*);
void affiche(FRACTION);
FRACTION somme(FRACTION, FRACTION);
int pgcd(int, int);


/* ========================================================================== */
/* Programme principal                                                        */
/* ========================================================================== */

int main()
{
    FRACTION f1, f2, f3;

    f2.Num = 5;
    f2.Den = 2;

/* -------------------------------------------------------------------------- */
/* Saisie de la fraction f1                                                   */
/* -------------------------------------------------------------------------- */
    printf("Saisie de la fraction f1\n");
    saisie(&f1);

    while(f1.Den == 0)
    {
        printf("Denominateur de la fraction f1 nul !\n\n");
        saisie(&f1);
    }

/* -------------------------------------------------------------------------- */
/* Calcul de la somme (simplifiee)                                            */
/* -------------------------------------------------------------------------- */
    f3 = somme(f1, f2);

/* -------------------------------------------------------------------------- */
/* Affichage de la somme                                                      */
/* -------------------------------------------------------------------------- */
    printf("\nSomme de ");
    affiche(f1);
    printf(" et de ");
    affiche(f2);
    printf(" = ");
    affiche(f3);
    printf("\n");

    return 0;
}

/* ========================================================================== */
/* Fonctions de gestion des fractions                                         */
/* ========================================================================== */

/* ========================================================================== */
/* Saisie de la fraction                                                      */
/* ========================================================================== */

void saisie(FRACTION* pf)
{
    char ligne[81];

    printf("Introduisez le numerateur : ");
    gets(ligne);
    pf->Num = atoi(ligne);

    printf("Introduisez le denominateur : ");
    gets(ligne);
    pf->Den = atoi(ligne);

    if (pf->Den <0)
    {
        pf->Den = -(pf->Den);
        pf->Num = -(pf->Num);
    }
}

/* ========================================================================== */
/* Somme de deux fractions                                                    */
/* ========================================================================== */

FRACTION somme(FRACTION f1, FRACTION f2)
{
    int PGCD;
    FRACTION f3;

    f3.Num = (f1.Num * f2.Den) + (f2.Num * f1.Den);
    f3.Den = f1.Den * f2.Den;

    if (f3.Num == 0)
    {
        f3.Den = 1;
    }
    else
    {
        if (f3.Num > 0) PGCD = pgcd(f3.Num, f3.Den);
        else            PGCD = pgcd(-f3.Num, f3.Den);

        f3.Num = f3.Num / PGCD;
        f3.Den = f3.Den / PGCD;
    }

    return f3;
}

/* ========================================================================== */
/* pgcd de deux entiers                                                       */
/* ========================================================================== */

int pgcd(int n1, int n2)
{
    while (n1 != n2)
    {
        if (n1 > n2) n1 -= n2;
        else         n2 -= n1;
    }
    return n1;
}

/* ========================================================================== */
/* Affichage de la fraction                                                   */
/* ========================================================================== */

void affiche(FRACTION f)
{
    if (f.Den != 1)
    {
        printf("%d/%d", f.Num, f.Den);
    }
    else
    {
        printf("%d", f.Num);
    }
}
