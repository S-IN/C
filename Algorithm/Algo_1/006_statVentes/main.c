/* ========================================================================== */
/* Version 1 : structures logiques                                            */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* -------------------------------------------------------------------------- */
/* Structure VERSEMENT                                                        */
/* -------------------------------------------------------------------------- */
typedef struct
{
    char   nosect[3];
    char   norep[4];
    char   nocli[5];
    char   nofac[6];
    double mont;
    char   codpays[3];
} VERSEMENT;


int main()
{
    FILE* fichierVersements;
    VERSEMENT versement;

    char  crNosect[3];
    char  crNorep[4];
    char  crNocli[5];

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des versements                                        */
/* -------------------------------------------------------------------------- */
    fichierVersements = fopen("C:\\C\\fichiers\\versements", "rb");
    if (fichierVersements == NULL)
    {
        printf("\n*** ERREUR OUVERTURE FICHIER VERSEMENTS ***\n");
        exit (0);
    }

/* -------------------------------------------------------------------------- */
/* Debut du programme                                                         */
/* -------------------------------------------------------------------------- */
    fread(&versement, sizeof(VERSEMENT), 1, fichierVersements);

    do
    {

/* -------------------------------------------------------------------------- */
/* Debut secteur                                                              */
/* -------------------------------------------------------------------------- */
        strcpy(crNosect, versement.nosect);
        printf("Secteur %s\n", crNosect);

        do
        {

/* -------------------------------------------------------------------------- */
/* Debut representant                                                         */
/* -------------------------------------------------------------------------- */
            strcpy(crNorep, versement.norep);
            printf("   Representant %s\n", crNorep);

            do
            {

/* -------------------------------------------------------------------------- */
/* Debut client                                                               */
/* -------------------------------------------------------------------------- */
                strcpy(crNocli, versement.nocli);
                printf("      Client %s\n", crNocli);

                do
                {

/* -------------------------------------------------------------------------- */
/* Debut versement                                                            */
/* -------------------------------------------------------------------------- */
                    printf("         Facture %s\n", versement.nofac);

                    if (strcmp(versement.codpays, "") == 0)
                    {
                        /* Facture France */
                    }
                    else
                    {
                        /* Facture Export */
                    }

/* -------------------------------------------------------------------------- */
/* Fin versement                                                              */
/* -------------------------------------------------------------------------- */
                    fread(&versement, sizeof(VERSEMENT), 1, fichierVersements);
                }
                while ((!feof(fichierVersements)) &&
                        (strcmp(crNosect, versement.nosect) == 0) &&
                        (strcmp(crNorep, versement.norep)   == 0) &&
                        (strcmp(crNocli, versement.nocli)   == 0));

/* -------------------------------------------------------------------------- */
/* Fin client                                                                 */
/* -------------------------------------------------------------------------- */
            }
            while ((!feof(fichierVersements)) &&
                    (strcmp(crNosect, versement.nosect) == 0) &&
                    (strcmp(crNorep, versement.norep)   == 0));

/* -------------------------------------------------------------------------- */
/* Fin representant                                                           */
/* -------------------------------------------------------------------------- */
        }
        while ((!feof(fichierVersements)) &&
                (strcmp(crNosect, versement.nosect) == 0));

/* -------------------------------------------------------------------------- */
/* Fin secteur                                                                */
/* -------------------------------------------------------------------------- */
    }
    while(!feof(fichierVersements));


/* -------------------------------------------------------------------------- */
/* Fin programme                                                              */
/* -------------------------------------------------------------------------- */
    printf("\n\n");
    fclose(fichierVersements);

    return 0;
}
