/* ========================================================================== */
/* Projet : statVentes -- Statistique des ventes                              */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "C:\C\utilitaires\entetes\chaines.h"
#include "C:\C\utilitaires\entetes\temps.h"

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
/* -------------------------------------------------------------------------- */
/* DECLARATIONS                                                               */
/* -------------------------------------------------------------------------- */
/* Fichiers                                                                   */
/* -------------------------------------------------------------------------- */
    FILE* fichierVersements;
    FILE* edition;

    VERSEMENT versement;

/* -------------------------------------------------------------------------- */
/* Criteres de reference                                                      */
/* -------------------------------------------------------------------------- */
    char  crNosect[3];   /* Numero de secteur sur lequel on travaille         */
    char  crNorep[4];    /* Numero de representant sur lequel on travaille    */
    char  crNocli[5];    /* Numero de client sur lequel on travaille          */

/* -------------------------------------------------------------------------- */
/* Cumuls et calculs                                                          */
/* -------------------------------------------------------------------------- */
    double z01, z02, z03, z04, z05, z06, z07, z08, z09, z10, z11;

/* -------------------------------------------------------------------------- */
/* Lignes d'edition                                                           */
/* -------------------------------------------------------------------------- */
    char le1[81] = "";
    char le2[81] = "";
    char le3[81] = "";
    char ld1[81] = "";
    char lt1[81] = "";
    char lt2[81] = "";
    char lt3[81] = "";

    char chaineDate[11];
    char chaineNum[81];

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des versements                                        */
/* -------------------------------------------------------------------------- */
    fichierVersements = fopen("C:\\C\\fichiers\\versements", "rb");
    if (fichierVersements == NULL)
    {
        printf("\n*** ERREUR OUVERTURE FICHIER VERSEMENTS ***\n");
        exit(0);
    }

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier d'edition                                             */
/* -------------------------------------------------------------------------- */
    edition = fopen("C:\\C\\fichiers\\statVentes.txt", "wt");
    if (edition == NULL)
    {
        printf("*** ERREUR OUVERTURE FICHIER EDITION ***\n");
        exit(0);
    }

/* -------------------------------------------------------------------------- */
/* Debut programme                                                            */
/* -------------------------------------------------------------------------- */
    getDateSysteme6(chaineDate);

    fread(&versement, sizeof(VERSEMENT), 1, fichierVersements);

    z09 = 0;
    z10 = 0;
    z11 = 0;

    placeSousChaine(le1, chaineDate, 1, 'd');
    placeSousChaine(le1, "STATISTIQUE MENSUELLE DES VENTES", 17, 'd');

    placeSousChaine(le2, "SECTEUR", 29, 'd');
    placeSousChaine(le3, "REPRESENTANT", 1, 'd');
    placeSousChaine(le3, "CLIENT", 15, 'd');
    placeSousChaine(le3, "MONTANT FRANCE", 24, 'd');
    placeSousChaine(le3, "MONTANT EXPORT", 41, 'd');
    placeSousChaine(le3, "PRIME", 59, 'd');

    do
    {

/* -------------------------------------------------------------------------- */
/* Debut secteur                                                              */
/* -------------------------------------------------------------------------- */
        strcpy(crNosect, versement.nosect);

        z06 = 0;
        z07 = 0;
        z08 = 0;

        placeSousChaine(le2, versement.nosect, 37, 'd');

        fprintf(edition, "\f");
        fprintf(edition, "%s\n\n", le1);
        fprintf(edition, "%s\n\n", le2);
        fprintf(edition, "%s\n\n", le3);

        do
        {

/* -------------------------------------------------------------------------- */
/* Debut representant                                                         */
/* -------------------------------------------------------------------------- */
            strcpy(crNorep, versement.norep);

            z03 = 0;
            z04 = 0;

            placeSousChaine(ld1, versement.norep, 5, 'd');

            do
            {

/* -------------------------------------------------------------------------- */
/* Debut client                                                               */
/* -------------------------------------------------------------------------- */
                strcpy(crNocli, versement.nocli);

                z01 = 0;
                z02 = 0;

                placeSousChaine(ld1, versement.nocli, 16, 'd');

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
                if (z01 > 0)
                {
                    doubleChaineFr(z01, 2, chaineNum);
                    placeSousChaine(ld1, chaineNum, 35, 'g');
                }
                if (z02 > 0)
                {
                    doubleChaineFr(z02, 2, chaineNum);
                    placeSousChaine(ld1, chaineNum, 52, 'g');
                }
                fprintf(edition, "%s\n", ld1);
                strcpy(ld1, "");

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
            z06 += z03;
            z07 += z04;
            z08 += z05;

            placeSousChaine(lt1, "TOTAL REPRESENTANT", 1, 'd');
            doubleChaineFr(z03, 2, chaineNum);
            placeSousChaine(lt1, chaineNum, 35, 'g');
            doubleChaineFr(z04, 2, chaineNum);
            placeSousChaine(lt1, chaineNum, 52, 'g');
            doubleChaineFr(z05, 2, chaineNum);
            placeSousChaine(lt1, chaineNum, 65, 'g');
            fprintf(edition, "\n");
            fprintf(edition, "%s\n\n", lt1);
            strcpy(lt1, "");
        }
        while ((!feof(fichierVersements)) &&
                (strcmp(crNosect, versement.nosect) == 0));

/* -------------------------------------------------------------------------- */
/* Fin secteur                                                                */
/* -------------------------------------------------------------------------- */
        z09 += z06;
        z10 += z07;
        z11 += z08;

        placeSousChaine(lt2, "TOTAL SECTEUR", 1, 'd');
        doubleChaineFr(z06, 2, chaineNum);
        placeSousChaine(lt2, chaineNum, 35, 'g');
        doubleChaineFr(z07, 2, chaineNum);
        placeSousChaine(lt2, chaineNum, 52, 'g');
        doubleChaineFr(z08, 2, chaineNum);
        placeSousChaine(lt2, chaineNum, 65, 'g');

        fprintf(edition, "%s\n", lt2);
        strcpy(lt2, "");
    }
    while(!feof(fichierVersements));

/* -------------------------------------------------------------------------- */
/* Fin programme                                                              */
/* -------------------------------------------------------------------------- */
    placeSousChaine(lt3, "TOTAL GENERAL", 1, 'd');
    doubleChaineFr(z09, 2, chaineNum);
    placeSousChaine(lt3, chaineNum, 35, 'g');
    doubleChaineFr(z10, 2, chaineNum);
    placeSousChaine(lt3, chaineNum, 52, 'g');
    doubleChaineFr(z11, 2, chaineNum);
    placeSousChaine(lt3, chaineNum, 65, 'g');

    fprintf(edition, "\n");
    fprintf(edition, "%s\n", lt3);

    fclose(fichierVersements);
    fclose(edition);

    return 0;
}
