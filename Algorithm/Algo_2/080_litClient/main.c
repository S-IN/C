/* ========================================================================== */
/* litClient -- lecture du fichier client                                     */
/* ========================================================================== */

#include <string.h>
#include <stdio.h>

#include "C:\C\utilitaires\entetes\client.h"

int main()
{

/* -------------------------------------------------------------------------- */
/* VARIABLES                                                                  */
/* -------------------------------------------------------------------------- */
/* Variables pour l'utilisation des fichiers                                  */
/* -------------------------------------------------------------------------- */
   CLIENT client;
   FILE* fichierClients;

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des clients, en lecture                               */
/* -------------------------------------------------------------------------- */
   fichierClients = fopen("C:\\C\\fichiers\\client", "rb");

   if (fichierClients == NULL)
   {
      printf("***** ERREUR OUVERTURE FICHIER client *****\n");
   }

/* -------------------------------------------------------------------------- */
/* Impression du fichier des clients                                          */
/* -------------------------------------------------------------------------- */
   printf("FICHIER DES CLIENTS (client)\n\n");

   fread(&client, sizeof(CLIENT), 1, fichierClients);

   do
   {
      printf("%4s\n%-50s\n%-50s\n%5s  %-50s\n%3s  %2s\n%c %8.2f\n\n",
             client.noCli,
             client.nom,
             client.adresse,
             client.cPost,
             client.ville,
             client.noRep,
             client.codPays,
             client.codSit,
             client.solde);

      fread(&client, sizeof(CLIENT), 1, fichierClients);
   }
   while(!feof(fichierClients));

   fclose(fichierClients);

   return 0;
}
