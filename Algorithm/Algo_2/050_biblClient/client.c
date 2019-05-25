/* ========================================================================== */
/* client.c : fonctions de gestion du fichier client                          */
/* ========================================================================== */

#include <string.h>
#include <stdio.h>

#include "client.h"


/* -------------------------------------------------------------------------- */
/* litClient :   lecture d'un enregistrement du fichier client connaissant    */
/*               la clef (noCli).                                             */
/*                                                                            */
/*               La clef  doit etre renseignee avant l'appel.                 */
/*                                                                            */
/*               Valeur retournee : >0 (numero de l'enregistrement trouve)    */
/*                                   0 (non trouve)                           */
/* -------------------------------------------------------------------------- */
int litClient(CLIENT* c, FILE* fichier)
{

   CLIENT client;
   int trouve;
   int i;

/* -------------------------------------------------------------------------- */
/* Boucle de recherche séquentielle                                           */
/* -------------------------------------------------------------------------- */

   trouve = 0;

   i = 0;
   fseek(fichier, i * sizeof(CLIENT), SEEK_SET);
   fread(&client, sizeof(CLIENT), 1, fichier);

   while (!feof(fichier) && trouve == 0)
   {
      if(strcmp(client.noCli, c->noCli) == 0)
      {
         trouve = i + 1;
         *c = client;
      }

      i++;
      fseek(fichier, i * sizeof(CLIENT), SEEK_SET);
      fread(&client, sizeof(CLIENT), 1, fichier);
   }

   return trouve;
}


/* -------------------------------------------------------------------------- */
/* ecritClient : mise à jour ou ajout dans le fichier client connaissant      */
/*               la clef (noCli).                                             */
/*                                                                            */
/*               Remplir TOUS les champs avant d'écrire !                     */
/*                                                                            */
/*               Valeur retournee : >0 (numero de l'enregistrement ecrit)     */
/*                                   0 (non ecrit)                            */
/* -------------------------------------------------------------------------- */
int ecritClient(CLIENT* c, FILE* fichier)
{
   CLIENT client;
   int trouve;
   int i;

/* -------------------------------------------------------------------------- */
/* Boucle de recherche séquentielle                                           */
/* -------------------------------------------------------------------------- */
   trouve = 0;

   i = 0;
   fseek(fichier, i * sizeof(CLIENT), SEEK_SET);
   fread(&client, sizeof(CLIENT), 1, fichier);

   while (!feof(fichier) && trouve == 0)
   {
      if(strcmp(client.noCli, c->noCli) == 0)
      {
         trouve = i + 1;
      }

      i++;
      fseek(fichier, i * sizeof(CLIENT), SEEK_SET);
      fread(&client, sizeof(CLIENT), 1, fichier);
   }

   if (trouve > 0)
   {
      fseek(fichier, (trouve - 1) * sizeof(CLIENT), SEEK_SET);
      fwrite(c, sizeof(CLIENT), 1, fichier);
   }
   else
   {
      fseek(fichier, i * sizeof(CLIENT), SEEK_SET);
      fwrite(c, sizeof(CLIENT), 1, fichier);
      trouve = i;
   }

   return trouve;
}
