/* ========================================================================== */
/* Projet : biblAgences                                                       */
/* -------------------------------------------------------------------------- */
/* main.c : affichage du fichier des agences                                  */
/* ========================================================================== */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "agences.h"


int main()
{
    FILE* fichierAgences;
    AGENCE agence;

    int numEnreg;
    int numAgence;
    char ligne[51];

    fichierAgences = fopen("..\\fichiers\\agences", "rb");

    if (fichierAgences == NULL)
    {
        printf("***** ERREUR OUVERTURE FICHIER AGENCES *****\n\n");
        exit(1);
    }

    printf("Entrer le numero d'agence :\n\n");

    gets(ligne);
    numAgence = atoi(ligne);

    numEnreg = chercheAgence(numAgence, fichierAgences);

    printf("Le numero d'enregistrement est %d :\n\n", numEnreg);

    if(numEnreg != -1)
    {
        fseek(fichierAgences, numEnreg*sizeof(AGENCE), SEEK_SET);
        fread(&agence, sizeof(AGENCE), 1, fichierAgences);
        printf("Le numero d'agence de %s est %d :\n\n", agence.nom, agence.numero);
    }

    fclose(fichierAgences);
    return 0;
}
