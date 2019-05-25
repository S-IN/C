/* ========================================================================== */
/* Compter le nombre de 'e' contenus dans une chaine saisie au clavier        */
/* (maximum 80 caracteres)                                                    */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>

int compteLettres(char* ligne, char lettre);

int main()
{
    char ligne[81];
    char lettre;

    printf("Entrer une ligne (maximum 80 caracteres) :\n");
    gets(ligne);

    lettre = 'e';

    printf("\nNombre de '%c' : %d.\n", lettre, compteLettres(ligne, lettre));

    return 0;
}

/* -------------------------------------------------------------------------- */
/* Fonction compteLettres :                                                   */
/* -------------------------------------------------------------------------- */
/* Parametres : ligne  : chaine examinee                                      */
/*              lettre : lettre cherchee                                      */
/* -------------------------------------------------------------------------- */

int compteLettres(char* ligne, char lettre)
{
    int compteur;
    char* debut;

    compteur = 0;
    debut = strchr(ligne, lettre);

    while (debut!= 0)
    {
        compteur++;
        debut++;
        debut = strchr(debut, lettre);
    }

    return compteur;
}
