/* ========================================================================== */
/* Projet : factures3  --  editions sans saut de page                         */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "C:\C\utilitaires\entetes\chaines.h"
#include "C:\C\utilitaires\entetes\temps.h"
#include "C:\C\utilitaires\entetes\client.h"

typedef struct
{
   char  noComm[7];
   char  noCli[5];
   char  noProd[5];
   int   quantite;
   char  desig[21];
   float prix;
   char  date[11];
} COMMANDE;


/* ========================================================================== */
/* PROGRAMME PRINCIPAL                                                        */
/* ========================================================================== */

int main()
{

/* -------------------------------------------------------------------------- */
/* VARIABLES                                                                  */
/* -------------------------------------------------------------------------- */
/* Variables pour l'utilisation des fichiers                                  */
/* -------------------------------------------------------------------------- */
   FILE* fichierCommandes;
   COMMANDE commande;

   FILE* fichierCommandesDep;
   COMMANDE commandeDep;

   FILE* fichierClients;
   CLIENT client;

   FILE* fichierEdition;

/* -------------------------------------------------------------------------- */
/* Criteres de reference                                                      */
/* -------------------------------------------------------------------------- */
   char crNoCli[5];
   char crNoComm[7];
   char crNoCommd[7];

/* -------------------------------------------------------------------------- */
/* Lignes d'edition                                                           */
/* -------------------------------------------------------------------------- */
   char le1[101] = "";
   char le2[101] = "";
   char le3[101] = "";
   char le4[101] = "";
   char le5[101] = "";
   char ld1[101] = "";
   char le6[101] = "";
   char lt1[101] = "";
   char lt2[101] = "";
   char lt3[101] = "";
   char lt4[101] = "";

/* -------------------------------------------------------------------------- */
/* Variables de travail                                                       */
/* -------------------------------------------------------------------------- */
   char chaineDate[11];  /* Chaine pour la mise en forme de la date systeme   */
   char chaineNum[81];   /* Chaine pour la conversion de valeurs numeriques   */
   char ligne[81];       /* Ligne pour la saisie du premier numero de facture */
   int  numFac;          /* Numero de facture                                 */
   int  numPage;         /* Numero de page                                    */

/* -------------------------------------------------------------------------- */
/* Totaux                                                                     */
/* -------------------------------------------------------------------------- */
   float montant;        /* Montant d'un produit                              */
   float sommeMontants;  /* Somme des montants d'une facture                  */

   float z01, z02, z03, z04;

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier binaire des commandes                                 */
/* -------------------------------------------------------------------------- */
   fichierCommandes = fopen("C:\\C\\fichiers\\comm", "rb");

   if (fichierCommandes == NULL)
   {
      printf("***** ERREUR OUVERTURE FICHIER comm *****");
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier binaire des commandes de depannage                    */
/* -------------------------------------------------------------------------- */
   fichierCommandesDep = fopen("C:\\C\\fichiers\\commd", "rb");

   if (fichierCommandesDep == NULL)
   {
      printf("***** ERREUR OUVERTURE FICHIER commd *****");
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier binaire des clients                                   */
/* -------------------------------------------------------------------------- */
   fichierClients = fopen("C:\\C\\fichiers\\client", "r+b");

   if (fichierClients == NULL)
   {
      printf("***** ERREUR OUVERTURE FICHIER client *****");
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier d'edition                                             */
/* -------------------------------------------------------------------------- */
   fichierEdition = fopen("C:\\C\\fichiers\\editionFactures.txt", "wt");

   if (fichierEdition == NULL)
   {
      printf("*** ERREUR OUVERTURE FICHIER editionFactures ***\n");
      exit(0);
   }

/* -------------------------------------------------------------------------- */
/* DEBUT                                                                      */
/* -------------------------------------------------------------------------- */

   getDateSysteme8(chaineDate);                  /* Date systeme (JJ/MM/AAAA) */

   printf("Entrer le premier numero de facture : ");
   gets(ligne);
   numFac = atoi(ligne);            /* Premier numero de facture (6 chiffres) */

   placeSousChaine(le6, "D E P A N N A G E", 36, 'd');

   fread(&commande,  sizeof(COMMANDE), 1, fichierCommandes);
   if (feof(fichierCommandes))
      chaineMax(commande.noCli, sizeof(commande.noCli));

   fread(&commandeDep, sizeof(COMMANDE), 1, fichierCommandesDep);
   if (feof(fichierCommandesDep))
      chaineMax(commandeDep.noCli, sizeof(commandeDep.noCli));

   do
   {

/* -------------------------------------------------------------------------- */
/* Debut client                                                               */
/* -------------------------------------------------------------------------- */
      strcpy(crNoCli, commande.noCli);

      sommeMontants = 0;

      strcpy(client.noCli, commande.noCli);
      litClient(&client, fichierClients);

      placeSousChaine(le1, crNoCli, 17, 'd');


      numPage = 1;
      sprintf(chaineNum, "%d", numPage);
      placeSousChaine(le1, chaineNum, 33, 'd');
      fprintf(fichierEdition, "\f%s\n\n\n\n\n\n", le1);
      strcpy(le1, "");

      placeSousChaine(le2, client.nom, 10, 'd');
      fprintf(fichierEdition, "%s\n\n", le2);
      strcpy(le2, "");

      placeSousChaine(le3, client.adresse, 10, 'd');
      fprintf(fichierEdition, "%s\n", le3);
      strcpy(le3, "");

      placeSousChaine(le4, client.cPost, 10, 'd');
      placeSousChaine(le4, client.ville, 16, 'd');
      fprintf(fichierEdition, "%s\n\n\n\n\n\n", le4);
      strcpy(le4, "");

      sprintf(chaineNum, "%d", numFac);
      placeSousChaine(le5, chaineNum, 22, 'd');
      placeSousChaine(le5, chaineDate, 36, 'd');
      placeSousChaine(le5, client.codPays, 80, 'd');
      placeSousChaine(le5, client.noRep, 84, 'd');
      fprintf(fichierEdition, "%s\n\n\n\n\n\n", le5);
      strcpy(le5, "");

      do
      {

/* -------------------------------------------------------------------------- */
/* Debut commande                                                             */
/* -------------------------------------------------------------------------- */
         strcpy(crNoComm, commande.noComm);

         placeSousChaine(ld1, crNoComm, 4, 'd');
         placeSousChaine(ld1, commande.date, 15, 'd');

         do
         {

/* -------------------------------------------------------------------------- */
/* Traitement produit                                                         */
/* -------------------------------------------------------------------------- */
            montant = commande.quantite * commande.prix;
            sommeMontants += montant;

            placeSousChaine(ld1, commande.noProd, 27, 'd');
            placeSousChaine(ld1, commande.desig, 37, 'd');
            sprintf(chaineNum, "%d", commande.quantite);
            placeSousChaine(ld1, chaineNum, 63, 'g');
            doubleChaine(commande.prix, 2, chaineNum);
            placeSousChaine(ld1, chaineNum, 76, 'g');
            doubleChaine(montant, 2, chaineNum);
            placeSousChaine(ld1, chaineNum, 89, 'g');

            fprintf(fichierEdition, "%s\n\n", ld1);
            strcpy(ld1, "");

            fread(&commande, sizeof(COMMANDE), 1, fichierCommandes);
            if (feof(fichierCommandes))
               chaineMax(commande.noCli, sizeof(commande.noCli));
         }
         while((strcmp(commande.noCli, crNoCli)==0) &&
               (strcmp(commande.noComm, crNoComm) == 0));

/* -------------------------------------------------------------------------- */
/* Fin commande                                                               */
/* -------------------------------------------------------------------------- */
      }
      while(strcmp(commande.noCli, crNoCli)==0);

/* -------------------------------------------------------------------------- */
/* Inter1 : Y-a-t'il des commandes de dépannage ?                             */
/* -------------------------------------------------------------------------- */
      if(strcmp(commandeDep.noCli, crNoCli) == 0)
      {

/* -------------------------------------------------------------------------- */
/* Debut groupe commande depannage                                            */
/* -------------------------------------------------------------------------- */
         fprintf(fichierEdition, "%s\n\n", le6);

         do
         {

/* -------------------------------------------------------------------------- */
/* Debut commande depannage                                                   */
/* -------------------------------------------------------------------------- */
            strcpy(crNoCommd, commandeDep.noComm);

            placeSousChaine(ld1, crNoCommd, 4, 'd');
            placeSousChaine(ld1, commandeDep.date, 15, 'd');

            do
            {

/* -------------------------------------------------------------------------- */
/* Traitement produit depannage                                               */
/* -------------------------------------------------------------------------- */
               montant = commandeDep.quantite * commandeDep.prix;
               sommeMontants += montant;

               placeSousChaine(ld1, commandeDep.noProd, 27, 'd');
               placeSousChaine(ld1, commandeDep.desig, 37, 'd');
               sprintf(chaineNum, "%d", commandeDep.quantite);
               placeSousChaine(ld1, chaineNum, 63, 'g');
               doubleChaine(commandeDep.prix, 2, chaineNum);
               placeSousChaine(ld1, chaineNum, 76, 'g');
               doubleChaine(montant, 2, chaineNum);
               placeSousChaine(ld1, chaineNum, 89, 'g');

               fprintf(fichierEdition, "%s\n\n", ld1);
               strcpy(ld1, "");

               fread(&commandeDep, sizeof(COMMANDE), 1, fichierCommandesDep);
               if (feof(fichierCommandesDep))
                  chaineMax(commandeDep.noCli, sizeof(commandeDep.noCli));
            }
            while((strcmp(commandeDep.noCli, crNoCli)==0) &&
                  (strcmp(commandeDep.noComm, crNoCommd) == 0));

/* -------------------------------------------------------------------------- */
/* Fin commande depannage                                                     */
/* -------------------------------------------------------------------------- */
         }
         while(strcmp(commandeDep.noCli, crNoCli)==0);

/* -------------------------------------------------------------------------- */
/* Fin groupe commande depannage                                              */
/* -------------------------------------------------------------------------- */
      }

/* -------------------------------------------------------------------------- */
/* Fin client                                                                 */
/* -------------------------------------------------------------------------- */
      if (sommeMontants > 25000.00f)
      {
         z01 = sommeMontants * 0.02f;
         doubleChaine(z01, 2, chaineNum);
         placeSousChaine(lt1, chaineNum, 89, 'g');
      }
      else
      {
         z01 = 0.0f;
      }

      z02 = sommeMontants - z01;
      z03 = z02 * 0.196f;
      z04 = z02 + z03;

      fprintf(fichierEdition, "%s\n\n", lt1);
      strcpy(lt1, "");

      doubleChaine(z02, 2, chaineNum);
      placeSousChaine(lt2, chaineNum, 89, 'g');
      fprintf(fichierEdition, "%s\n\n", lt2);
      strcpy(lt2, "");

      doubleChaine(z03, 2, chaineNum);
      placeSousChaine(lt3, chaineNum, 89, 'g');
      fprintf(fichierEdition, "%s\n\n\n", lt3);
      strcpy(lt3, "");

      doubleChaine(z04, 2, chaineNum);
      placeSousChaine(lt4, chaineNum, 89, 'g');
      fprintf(fichierEdition, "%s\n\n", lt4);
      strcpy(lt4, "");

      numFac++;
   }
   while(!feof(fichierCommandes));

   fclose(fichierCommandes);
   fclose(fichierCommandesDep);
   fclose(fichierClients);
   fclose(fichierEdition);

   return 0;
}
