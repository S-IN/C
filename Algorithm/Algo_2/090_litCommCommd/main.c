/* ========================================================================== */
/* litCommCommd : lecture du fichier commande (comm) et du fichier commande   */
/* depannage (commd)                                                          */
/* ========================================================================== */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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


int main()
{
   FILE * fichierCommandes;
   FILE * fichierCommandesDep;
   COMMANDE commande;

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
/* Impression du fichier des commandes                                        */
/* -------------------------------------------------------------------------- */
   printf("FICHIER DES COMMANDES (comm)\n\n");

   fread(&commande, sizeof(COMMANDE), 1, fichierCommandes);

   do
   {
      printf("%6s  %4s  %4s  %4d  %20s  %7.2f %10s\n",
             commande.noComm,
             commande.noCli,
             commande.noProd,
             commande.quantite,
             commande.desig,
             commande.prix,
             commande.date);

      fread(&commande, sizeof(COMMANDE), 1, fichierCommandes);
   }
   while(!feof(fichierCommandes));

/* -------------------------------------------------------------------------- */
/* Impression du fichier des commandes depannage                              */
/* -------------------------------------------------------------------------- */
   printf("\nFICHIER DES COMMANDES DEPANNAGE (commd)\n\n");

   fread(&commande, sizeof(COMMANDE), 1, fichierCommandesDep);

   do
   {
      printf("%6s  %4s  %4s  %4d  %20s  %7.2f %10s\n",
             commande.noComm,
             commande.noCli,
             commande.noProd,
             commande.quantite,
             commande.desig,
             commande.prix,
             commande.date);

      fread(&commande, sizeof(COMMANDE), 1, fichierCommandesDep);
   }
   while(!feof(fichierCommandesDep));


   fclose(fichierCommandes);
   fclose(fichierCommandesDep);

   return 0;
}

