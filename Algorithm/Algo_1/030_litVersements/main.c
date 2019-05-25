/* ========================================================================== */
/* litVersements -- affichage du fichier des versements                       */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>
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
}VERSEMENT;


int main()
{
   FILE* fichierVersements;
   char nomfich[201];

   VERSEMENT versement;

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des ventes (versements)                               */
/* -------------------------------------------------------------------------- */
   strcpy(nomfich, "C:\\C\\fichiers\\versements");

   fichierVersements = fopen(nomfich, "rb");

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
      printf("%s %s %s %s %10.2f %s\n", versement.nosect,
                                        versement.norep,
                                        versement.nocli,
                                        versement.nofac,
                                        versement.mont,
                                        versement.codpays);

      fread(&versement, sizeof(VERSEMENT), 1, fichierVersements);
   }
   while(!feof(fichierVersements));


/* -------------------------------------------------------------------------- */
/* Fin programme                                                              */
/* -------------------------------------------------------------------------- */
   fclose(fichierVersements);

   return 0;
}

