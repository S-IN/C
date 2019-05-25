/* ========================================================================== */
/* Version 2 : calculs, cumuls                                                */
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

    double z01, z02, z03, z04, z05, z06, z07, z08, z09, z10, z11;

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

    z09 = 0;
    z10 = 0;
    z11 = 0;

    do
    {

/* -------------------------------------------------------------------------- */
/* Debut secteur                                                              */
/* -------------------------------------------------------------------------- */
        strcpy(crNosect, versement.nosect);

        z06 = 0;
        z07 = 0;
        z08 = 0;

        do
        {

/* -------------------------------------------------------------------------- */
/* Debut representant                                                         */
/* -------------------------------------------------------------------------- */
            strcpy(crNorep, versement.norep);

            z03 = 0;
            z04 = 0;

            do
            {

/* -------------------------------------------------------------------------- */
/* Debut client                                                               */
/* -------------------------------------------------------------------------- */
                strcpy(crNocli, versement.nocli);

                z01 = 0;
                z02 = 0;

                do
                {

/* -------------------------------------------------------------------------- */
/* Debut versement                                                            */
/* -------------------------------------------------------------------------- */
                    if (strcmp(versement.codpays, "") == 0)
                    {
/* Facture France */
                        z01+=versement.mont;
                    }
                    else
                    {
/* Facture Export */
                        z02+=versement.mont;
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
                printf("z01 = %9.2f  z02 = %9.2f\n", z01, z02);

                z03 += z01;
                z04 += z02;
            }
            while ((!feof(fichierVersements)) &&
                    (strcmp(crNosect, versement.nosect) == 0) &&
                    (strcmp(crNorep, versement.norep)   == 0));

/* -------------------------------------------------------------------------- */
/* Fin representant                                                           */
/* -------------------------------------------------------------------------- */
            z05 = (z03 + z04) * 0.015;
            printf("z03 = %9.2f  z04 = %9.2f  z05 = %9.2f\n", z03, z04, z05);
            z06 += z03;
            z07 += z04;
            z08 += z05;
        }
        while ((!feof(fichierVersements)) &&
                (strcmp(crNosect, versement.nosect) == 0));

/* -------------------------------------------------------------------------- */
/* Fin secteur                                                                */
/* -------------------------------------------------------------------------- */
        printf("z06 = %9.2f  z07 = %9.2f  z08 = %9.2f\n", z06, z07, z08);
        z09 += z06;
        z10 += z07;
        z11 += z08;
    }
    while(!feof(fichierVersements));


/* -------------------------------------------------------------------------- */
/* Fin programme                                                              */
/* -------------------------------------------------------------------------- */
    printf("z09 = %9.2f  z10 = %9.2f  z11 = %9.2f\n", z09, z10, z11);
    printf("\n\n");

    fclose(fichierVersements);

    return 0;
}
