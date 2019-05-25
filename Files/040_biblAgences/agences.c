/* ========================================================================== */
/* agences.c : fonctions de gestion d'agence                                  */
/* ========================================================================== */

#include <stdio.h>

#include "agences.h"

/* -------------------------------------------------------------------------- */
/* Recherche du numero d'ENREGISTREMENT de l'agence numeroAgence              */
/* -------------------------------------------------------------------------- */
int chercheAgence(int numeroAgence, FILE* fichierAgences)
{
    AGENCE agence;
    int retour;
    int i;

    retour = -1;
    i = 0;

    fseek(fichierAgences, i * sizeof(AGENCE), SEEK_SET);
    fread(&agence, sizeof(AGENCE), 1, fichierAgences);

    while ((!feof(fichierAgences)) && (retour == -1))
    {
        if (agence.numero == numeroAgence)
        {
            retour = i;
        }

        i++;

        fseek(fichierAgences, i * sizeof(AGENCE), SEEK_SET);
        fread(&agence, sizeof(AGENCE), 1, fichierAgences);
    }

    return retour;
}
