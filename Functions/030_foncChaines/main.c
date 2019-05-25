/* ========================================================================== */
/* Supprimer tous les caracteres 'e' contenus dans une chaine saisie au       */
/* clavier (maximum 80 caracteres)                                            */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>

void enleveLettres(char* ligne, char lettre);


int main()
{
    char ligne[81];
    char lettre;

    printf("Entrer une ligne (maximum 80 caracteres) :\n");
    gets(ligne);

    lettre = 'e';

    enleveLettres(ligne, lettre);

    printf("\n\n");
    puts(ligne);

    return 0;
}

/* -------------------------------------------------------------------------- */
/* Fonction enleveLettres :                                                   */
/* -------------------------------------------------------------------------- */
/* Parametres : ligne  : chaine a traiter                                     */
/*              lettre : lettre a enlever                                     */
/* -------------------------------------------------------------------------- */

void enleveLettres(char* ligne, char lettre)
{
    char * adresse;
    adresse = strchr(ligne, lettre);

    while (adresse != 0)
    {
        strcpy(adresse, adresse + 1);
        adresse = strchr(adresse, lettre);
    }
}
