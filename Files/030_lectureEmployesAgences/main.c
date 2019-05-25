/* ========================================================================== */
/* Projet : lectureEmployesAgences : lecture du fichier des employes          */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "\\10.75.96.101\User\Stagiaires\Group64\Reference\c\utilitaires\entetes\agences.h"

typedef struct
{
    int numero;
    char nom[51];
    char prenom[41];
    int numeroAgence;
} EMPLOYE;


int main()
{
    EMPLOYE employe;
    FILE* fichierEmployes;

    AGENCE agence;
    FILE* fichierAgences;

    int numEnregAgence;

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des employes (en lecture)                             */
/* -------------------------------------------------------------------------- */
    fichierEmployes = fopen("..\\fichiers\\employes", "rb");

    if (fichierEmployes == NULL)
    {
        printf("***** ERREUR OUVERTURE FICHIER EMPLOYES *****\n\n");
        exit(1);
    }

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des agences (en lecture)                              */
/* -------------------------------------------------------------------------- */
    fichierAgences = fopen("..\\fichiers\\agences", "rb");

    if (fichierAgences == NULL)
    {
        printf("***** ERREUR OUVERTURE FICHIER AGENCES *****\n\n");
        exit(2);
    }


/* -------------------------------------------------------------------------- */
/* Boucle de lecture et d'affichage des employes                              */
/* -------------------------------------------------------------------------- */
    printf("LISTE DES EMPLOYES\n\n");
    fread(&employe, sizeof(EMPLOYE), 1, fichierEmployes);

    while (!feof(fichierEmployes))
    {

/* -------------------------------------------------------------------------- */
/* Recherche de l'enregistrement de l'agence                                  */
/* -------------------------------------------------------------------------- */
        numEnregAgence =  chercheAgence(employe.numeroAgence, fichierAgences);

/* -------------------------------------------------------------------------- */
/* L'agence existe, on lit l'enregistrement correspondant                     */
/* -------------------------------------------------------------------------- */
        if (numEnregAgence != -1)
        {
            fseek(fichierAgences, numEnregAgence * sizeof(AGENCE), SEEK_SET);
            fread(&agence, sizeof(AGENCE), 1, fichierAgences);

            printf("%3d  %s %s (%s)\n", employe.numero,
                   employe.prenom,
                   employe.nom,
                   agence.nom);
        }

/* -------------------------------------------------------------------------- */
/* L'agence n'existe pas                                                      */
/* -------------------------------------------------------------------------- */
        else
        {
            printf("%3d  %s %s (%d : agence inconnue)\n", employe.numero,
                   employe.prenom,
                   employe.nom,
                   employe.numeroAgence);
        }

        fread(&employe, sizeof(EMPLOYE), 1, fichierEmployes);
    }

    fclose(fichierEmployes);
    fclose(fichierAgences);

    return 0;
}
