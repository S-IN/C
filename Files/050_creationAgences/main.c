/* ========================================================================== */
/* Projet : creationAgences -- creation du fichier des agences                */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int numero;
    char nom[81];
} AGENCE;


int main()
{
    FILE* fichierAgences;
    AGENCE agence;
    char ligne[81];

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des agences, en ecriture.                             */
/* Si le fichier existe deja, on l'ecrase.                                    */
/* -------------------------------------------------------------------------- */
    fichierAgences = fopen("..\\fichiers\\agences", "wb");

    if (fichierAgences == NULL)
    {
        printf("***** ERREUR OUVERTURE FICHIER agences *****\n");
        exit(1);
    }

/* -------------------------------------------------------------------------- */
/* Boucle de saisie des agences.                                              */
/* Elle s'arrete quand on tape ENTREE pour la saisie du numero                */
/* -------------------------------------------------------------------------- */
    printf("Numero de l'agence : ");
    gets(ligne);

    while(ligne[0] != 0)
    {
        agence.numero = atoi(ligne);

        printf("Nom de l'agence : ");
        gets(agence.nom);

        fwrite(&agence, sizeof(AGENCE), 1, fichierAgences);

        printf("\n\nNumero de l'agence : ");
        gets(ligne);
    }

    fclose(fichierAgences);

    return 0;
}
