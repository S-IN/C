/* ========================================================================== */
/* Projet : "chaines" : exercice 2                                            */
/* -------------------------------------------------------------------------- */
/* Supprimer tous les caracteres 'e' contenus dans une chaine saisie au       */
/* clavier (maximum 80 caracteres)                                            */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>

int main()
{
    char ligne[81];
    char * adresse;

    printf("Entrer une ligne (max 80 caracteres) :\n");
    gets(ligne);

    adresse = strchr(ligne, 'e');

    while (adresse != 0)
    {
        strcpy(adresse, adresse + 1);
        adresse = strchr(adresse, 'e');
    }

    puts(ligne);

    return 0;
}
