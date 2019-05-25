/* ========================================================================== */
/* initClient -- initialisation du fichier client                             */
/* ========================================================================== */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "C:\C\utilitaires\entetes\client.h"

int main()
{
   FILE* fichierClients;
   CLIENT client;

   char ligne[81];

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des clients                                           */
/* -------------------------------------------------------------------------- */
   fichierClients = fopen("C:\\C\\fichiers\\client", "ab");

   if (fichierClients == NULL)
   {
      printf("***** ERREUR OUVERTURE FICHIER client *****\n");
   }
   else
   {

/* -------------------------------------------------------------------------- */
/* Saisie du numero de client :                                               */
/* -------------------------------------------------------------------------- */

      printf("\n\nNumero de client : ");
      gets(client.noCli);

/* -------------------------------------------------------------------------- */
/* Saisie des autres proprietes du client :                                   */
/* -------------------------------------------------------------------------- */

      while (client.noCli[0] != 0)
      {
         printf("Nom : ");
         gets(client.nom);

         printf("Adresse : ");
         gets(client.adresse);

         printf("Code postal : ");
         gets(client.cPost);

         printf("Ville : ");
         gets(client.ville);

         printf("Numero de représentant : ");
         gets(client.noRep);

         printf("Code pays (\"  \" ou \"XX\" : ");
         gets(client.codPays);

         printf("Code situation : ");
         gets(ligne);
         client.codSit = ligne[0];

         printf("Solde : ");
         gets(ligne);
         client.solde = (float)atof(ligne);

         fwrite(&client, sizeof(CLIENT), 1, fichierClients);

         printf("\n\nNumero de client : ");
         gets(client.noCli);
      }

      fclose(fichierClients);
   }

   return 0;
}
