/* ========================================================================== */
/* statCAHisto -- Statistiques sur les chiffres d'affaires (vente)            */
/* -------------------------------------------------------------------------- */
/* Version avec tableau et histogramme                                        */
/* ========================================================================== */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "C:\C\utilitaires\entetes\chaines.h"
#include "C:\C\utilitaires\entetes\rapport.h"

typedef struct
{
    char  noCli[5];
    char  dateFac[11];
    char  noProd[5];
    int   quantite;
    float prixHT;
} VENTE;

typedef struct
{
    float pQuinz[7];
    char* libMois;
    float totalMois;
    float dQuinz[7];
} MOIS;

typedef struct
{
    int annee[7];
    MOIS mois[12];
    float totalAnnee[7];
    float totalGeneral;
} TABLEAU;

typedef struct
{
    int jj;
    int mm;
    int aaaa;
} DATEINT;

DATEINT convDate(char* chaineDate);


int main(int argc, char* argv[])
{

/* -------------------------------------------------------------------------- */
/* VARIABLES                                                                  */
/* -------------------------------------------------------------------------- */
/* Variables pour l'utilisation des fichiers                                  */
/* -------------------------------------------------------------------------- */
    FILE * fichierVentes;
    VENTE vente;

    FILE* fichierEdition;
    FILE* histogramme;

/* -------------------------------------------------------------------------- */
/* derniereAnnee : annee de la derniere colonne du tableau                    */
/* premiereAnnee : annee de la premiere colonne du tableau                    */
/* -------------------------------------------------------------------------- */
    int derniereAnnee;
    int premiereAnnee;
    char chaineAnnee[81];

/* -------------------------------------------------------------------------- */
/* Tableau a remplir (et ses indices)                                         */
/* -------------------------------------------------------------------------- */
    TABLEAU tableau;
    int nLig;
    int nCol;

/* -------------------------------------------------------------------------- */
/* Variable pour recuperer la date de la facture sous forme de 3 entiers      */
/* -------------------------------------------------------------------------- */
    DATEINT dateInt;

/* -------------------------------------------------------------------------- */
/* Variables pour l'edition de l'histogramme                                  */
/* -------------------------------------------------------------------------- */
    FEUILLE feuille;
    TUYAU tableHisto[7];
    int valMaxi;
    float decimales;

/* -------------------------------------------------------------------------- */
/* Lignes d'edition                                                           */
/* -------------------------------------------------------------------------- */
    char lt1[133]     = "";
    char lEtoile[133] = "";
    char ld1[133]     = "";
    char ld2[133]     = "";
    char ld3[133]     = "";
    char ld2Vide[133] = "";
    char ld3Vide[133] = "";
    char ld4[133]     = "";

    char chaineNum[81];

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier binaire des ventes                                    */
/* -------------------------------------------------------------------------- */
    fichierVentes = fopen("C:\\C\\fichiers\\vente", "rb");

    if (fichierVentes == NULL)
    {
        printf("***** ERREUR OUVERTURE FICHIER vente *****\n");
        exit(0);
    }

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier d'edition                                             */
/* -------------------------------------------------------------------------- */
    fichierEdition = fopen("C:\\C\\fichiers\\statCA.txt", "wt");

    if (fichierEdition == NULL)
    {
        printf("*** ERREUR OUVERTURE FICHIER EDITION ***\n");
        exit(0);
    }

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier d'edition de l'histogramme                            */
/* -------------------------------------------------------------------------- */
    histogramme = fopen("C:\\C\\fichiers\\histoCA.txt", "wt");

    if (histogramme == NULL)
    {
        printf("*** ERREUR OUVERTURE FICHIER histogramme ***\n");
        exit(0);
    }

/* -------------------------------------------------------------------------- */
/* Saisie de l'annee de la 7eme colonne (ou recuperation dans argv)           */
/* -------------------------------------------------------------------------- */
    if (argc > 1)
    {
        strcpy(chaineAnnee, argv[1]);
    }
    else
    {
        printf("Entrer la date de facturation (annee de la septieme colonne) : ");
        gets(chaineAnnee);
    }

    derniereAnnee = atoi(chaineAnnee);
    premiereAnnee = derniereAnnee - 6;

/* -------------------------------------------------------------------------- */
/* DEBUT : remplissage (initialisation) du tableau                            */
/* -------------------------------------------------------------------------- */
/* Ligne des annees                                                           */
/* -------------------------------------------------------------------------- */
    for (nCol = 0; nCol < 7; nCol++)
    {
        tableau.annee[nCol] = premiereAnnee + nCol;
    }

/* -------------------------------------------------------------------------- */
/* Initialisation des mois                                                    */
/* -------------------------------------------------------------------------- */
    tableau.mois[0].libMois  = "JANVIER";
    tableau.mois[1].libMois  = "FEVRIER";
    tableau.mois[2].libMois  = "MARS";
    tableau.mois[3].libMois  = "AVRIL";
    tableau.mois[4].libMois  = "MAI";
    tableau.mois[5].libMois  = "JUIN";
    tableau.mois[6].libMois  = "JUILLET";
    tableau.mois[7].libMois  = "AOUT";
    tableau.mois[8].libMois  = "SEPTEMBRE";
    tableau.mois[9].libMois  = "OCTOBRE";
    tableau.mois[10].libMois = "NOVEMBRE";
    tableau.mois[11].libMois = "DECEMBRE";

    for (nLig = 0; nLig < 12; nLig++)
    {
        for (nCol = 0; nCol < 7; nCol++)
        {
            tableau.mois[nLig].pQuinz[nCol] = 0.0f;
            tableau.mois[nLig].dQuinz[nCol] = 0.0f;
        }
        tableau.mois[nLig].totalMois = 0.0f;
    }

/* -------------------------------------------------------------------------- */
/* Initialisation des totaux annee et general                                 */
/* -------------------------------------------------------------------------- */
    for (nCol = 0; nCol < 7; nCol++)
    {
        tableau.totalAnnee[nCol] = 0.0f;
    }

    tableau.totalGeneral = 0.0f;


/* -------------------------------------------------------------------------- */
/* Ligne de titre et ligne d'etoiles                                          */
/* -------------------------------------------------------------------------- */
    placeSousChaine(lt1, "** M.GINESTE **", 0, 'd');
    placeSousChaine(lt1, "STATISTIQUES CHIFFRES D'AFFAIRES", 46, 'd');

    remplirChaine(lEtoile, '*', 0, 124);

/* -------------------------------------------------------------------------- */
/* Etoiles de ld1, ld2, ld3                                                   */
/* -------------------------------------------------------------------------- */
    placeSousChaine(ld1, "*", 0, 'd');
    placeSousChaine(ld1, "*", 12, 'd');
    for (nCol = 1; nCol <= 8; nCol++)
        placeSousChaine(ld1, "*", 12 + (nCol * 14), 'd');
    placeSousChaine(ld1, "T O T A L", 113, 'd');

    placeSousChaine(ld2Vide, "*", 0, 'd');
    placeSousChaine(ld2Vide, "*", 12, 'd');
    for (nCol = 1; nCol <= 8; nCol++)
        placeSousChaine(ld2Vide, "*", 12 + (nCol * 14), 'd');

    remplirChaine(ld3Vide, '-', 12, 110);
    placeSousChaine(ld3Vide, "*", 0, 'd');
    placeSousChaine(ld3Vide, "*", 12, 'd');
    for (nCol = 1; nCol <= 8; nCol++)
        placeSousChaine(ld3Vide, "*", 12 + (nCol * 14), 'd');

    placeSousChaine(ld4, "*", 0, 'd');
    placeSousChaine(ld4, "*", 12, 'd');
    for (nCol = 1; nCol <= 8; nCol++)
        placeSousChaine(ld4, "*", 12 + (nCol * 14), 'd');
    placeSousChaine(ld4, "T O T A L", 2, 'd');

/* -------------------------------------------------------------------------- */
/* Caracteres et libelles des tuyaux de l'histogramme                         */
/* -------------------------------------------------------------------------- */
    tableHisto[0].car = '+';
    tableHisto[1].car = '-';
    tableHisto[2].car = '+';
    tableHisto[3].car = '-';
    tableHisto[4].car = '+';
    tableHisto[5].car = '-';
    tableHisto[6].car = '+';

    for (nCol = 0; nCol < 7; nCol++)
    {
        sprintf(chaineNum, "%d", tableau.annee[nCol]);
        strcpy(tableHisto[nCol].lib, chaineNum);
    }

    valMaxi = 0;

/* -------------------------------------------------------------------------- */
/* Remplissage du tableau a partir du fichier vente                           */
/* -------------------------------------------------------------------------- */
    fread(&vente, sizeof(VENTE), 1, fichierVentes);

    do
    {
        dateInt = convDate(vente.dateFac);

/* -------------------------------------------------------------------------- */
/* La date de la vente est dans le tableau                                    */
/* -------------------------------------------------------------------------- */
        if ((dateInt.aaaa >= premiereAnnee) && (dateInt.aaaa <= derniereAnnee))
        {
            nCol = dateInt.aaaa - premiereAnnee;
            nLig = dateInt.mm - 1;
            if (dateInt.jj < 16)
            {
                tableau.mois[nLig].pQuinz[nCol] += vente.prixHT;
            }
            else
            {
                tableau.mois[nLig].dQuinz[nCol] += vente.prixHT;
            }


            tableau.mois[nLig].totalMois += vente.prixHT;
            tableau.totalAnnee[nCol] += vente.prixHT;
            tableau.totalGeneral += vente.prixHT;
        }

        fread(&vente, sizeof(VENTE), 1, fichierVentes);
    }
    while(!feof(fichierVentes));

/* -------------------------------------------------------------------------- */
/* Affichage du tableau                                                       */
/* -------------------------------------------------------------------------- */
/* Lignes de titre                                                            */
/* -------------------------------------------------------------------------- */
    fprintf(fichierEdition, "%s\n\n", lt1);
    fprintf(fichierEdition, "%s\n", lEtoile);

/* -------------------------------------------------------------------------- */
/* Ligne des annees                                                           */
/* -------------------------------------------------------------------------- */
    for (nCol = 0; nCol < 7; nCol++)
    {
        sprintf(chaineNum, "%d", tableau.annee[nCol]);
        placeSousChaine(ld1, chaineNum, 18 + (nCol * 14), 'd');
    }
    fprintf(fichierEdition, "%s\n", ld1);
    fprintf(fichierEdition, "%s\n", lEtoile);

/* -------------------------------------------------------------------------- */
/* Lignes des mois                                                            */
/* -------------------------------------------------------------------------- */
    strcpy(ld2, ld2Vide);
    strcpy(ld3, ld3Vide);

    for (nLig = 0; nLig < 12; nLig++)
    {
        for (nCol = 0; nCol < 7; nCol++)
        {
            if (tableau.mois[nLig].pQuinz[nCol] > 0.0f)
            {
                doubleChaine(tableau.mois[nLig].pQuinz[nCol], 0, chaineNum);
                placeSousChaine(ld2, chaineNum, 24 + (nCol * 14), 'g');
            }
        }

        fprintf(fichierEdition, "%s\n", ld2);
        strcpy(ld2, ld2Vide);

        placeSousChaine(ld3, tableau.mois[nLig].libMois, 2, 'd');

        if (tableau.mois[nLig].totalMois > 0.0f)
        {
            doubleChaine(tableau.mois[nLig].totalMois, 0, chaineNum);
            placeSousChaine(ld3, chaineNum, 122, 'g');
        }

        fprintf(fichierEdition, "%s\n", ld3);
        strcpy(ld3, ld3Vide);

        for (nCol = 0; nCol < 7; nCol++)
        {
            if (tableau.mois[nLig].dQuinz[nCol] > 0.0f)
            {
                doubleChaine(tableau.mois[nLig].dQuinz[nCol], 0, chaineNum);
                placeSousChaine(ld2, chaineNum, 24 + (nCol * 14), 'g');
            }
        }

        fprintf(fichierEdition, "%s\n", ld2);
        strcpy(ld2, ld2Vide);

        fprintf(fichierEdition, "%s\n", lEtoile);
    }

/* -------------------------------------------------------------------------- */
/* On met les totaux annee dans les tuyaux de l'histogramme                   */
/* -------------------------------------------------------------------------- */
    for (nCol = 0; nCol < 7; nCol++)
    {
        tableHisto[nCol].valeur = (int)tableau.totalAnnee[nCol];
        decimales = tableau.totalAnnee[nCol] - (int)tableau.totalAnnee[nCol];
        if (decimales >= 0.5f) tableHisto[nCol].valeur++;

        if (tableHisto[nCol].valeur > valMaxi)
        {
            valMaxi = tableHisto[nCol].valeur;
        }
    }

/* -------------------------------------------------------------------------- */
/* Totaux annee et total general                                              */
/* -------------------------------------------------------------------------- */
    for (nCol = 0; nCol < 7; nCol++)
    {
        if (tableau.totalAnnee[nCol] > 0.0f)
        {
            doubleChaine(tableau.totalAnnee[nCol], 0, chaineNum);
            placeSousChaine(ld4, chaineNum, 24 + (nCol * 14), 'g');
        }
    }

    if (tableau.totalGeneral > 0.0f)
    {
        doubleChaine(tableau.totalGeneral, 0, chaineNum);
        placeSousChaine(ld4, chaineNum, 122, 'g');
    }

    fprintf(fichierEdition, "%s\n", ld4);
    fprintf(fichierEdition, "%s\n", lEtoile);

/* -------------------------------------------------------------------------- */
/* Impression de l'histogramme                                                */
/* -------------------------------------------------------------------------- */
    creerFeuille(&feuille, 60, 132);

    place(&feuille, "EUROS", 4, 2, 'd');
    place(&feuille, "STATISTIQUES CHIFFRES D'AFFAIRES", 1, 20, 'd');
    histo(&feuille, tableHisto, 7, valMaxi);

    imprimeFichier(&feuille, histogramme);
    libererFeuille(&feuille);

    fclose(fichierVentes);
    fclose(fichierEdition);
    fclose(histogramme);

    return 0;
}

/* ========================================================================== */
/* Fonction de conversion de la date (JJ/MM/AAAA) en 3 entiers                */
/* ========================================================================== */

DATEINT convDate(char* chaineDate)
{
    DATEINT dateInt;
    char prov[81];

    memcpy(prov, chaineDate, 2);
    prov[2] = 0;
    dateInt.jj = atoi(prov);

    memcpy(prov, chaineDate + 3, 2);
    prov[2] = 0;
    dateInt.mm = atoi(prov);

    memcpy(prov, chaineDate + 6, 4);
    prov[4] = 0;
    dateInt.aaaa = atoi(prov);

    return dateInt;
}
