/* ========================================================================== */
/* Projet : factures2  --  tests de la logique                                */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

#include "C:\C\utilitaires\entetes\chaines.h"
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

   char crNoCli[5];
   char crNoComm[7];
   char crNoCommd[7];

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
/* DEBUT                                                                      */
/* -------------------------------------------------------------------------- */
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

      strcpy(client.noCli, commande.noCli);
      litClient(&client, fichierClients);
      printf("Client : %15s\n", client.nom);

      do
      {

/* -------------------------------------------------------------------------- */
/* Debut commande                                                             */
/* -------------------------------------------------------------------------- */
         strcpy(crNoComm, commande.noComm);
         printf("   Commande : %s\n", crNoComm);

         do
         {

/* -------------------------------------------------------------------------- */
/* Traitement produit                                                         */
/* -------------------------------------------------------------------------- */
            printf("      Produit : %s\n", commande.noProd);

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
         do
         {

/* -------------------------------------------------------------------------- */
/* Debut commande depannage                                                   */
/* -------------------------------------------------------------------------- */
            strcpy(crNoCommd, commandeDep.noComm);
            printf("   Commande dep : %s\n", crNoCommd);

            do
            {

/* -------------------------------------------------------------------------- */
/* Traitement produit depannage                                               */
/* -------------------------------------------------------------------------- */
               printf("      Produit : %s\n", commandeDep.noProd);

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
   }
   while(!feof(fichierCommandes));


   fclose(fichierCommandes);
   fclose(fichierCommandesDep);
   fclose(fichierClients);

   return 0;
}
