/* ========================================================================== */
/* initVersements -- initialisation du fichier des versements                 */
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
}VERSEMENT;

int main()
{
   FILE* fichierVersements;
   char nomFichier[81];

   VERSEMENT versement;
   char ligne[81];

/* -------------------------------------------------------------------------- */
/* Ouverture du fichier des ventes, en ecriture.                              */
/* Si le fichier existe deja, on l'ecrase.                                    */
/* -------------------------------------------------------------------------- */
   strcpy(nomFichier, "C:\\C\\fichiers\\versements");

   fichierVersements = fopen(nomFichier, "ab");

   if (fichierVersements == NULL)
   {
      printf("\n*** ERREUR OUVERTURE FICHIER VERSEMENTS ***\n");
      exit (0);
   }

/* -------------------------------------------------------------------------- */
/* Saisie des VERSEMENTs                                                        */
/* -------------------------------------------------------------------------- */
    printf("\n\nNumero du secteur : ");
    gets(versement.nosect);

    while (versement.nosect[0] != 0)
    {
        printf("Numero du representant : ");
        gets(versement.norep);
        printf("Numero du client : ");
        gets(versement.nocli);
        printf("Numero de versement : ");
        gets(versement.nofac);
        printf("Montant : ");
        gets(ligne);
        versement.mont = atof(ligne);
        printf("Code pays : ");
        gets(versement.codpays);


        fwrite(&versement, sizeof(VERSEMENT), 1, fichierVersements);

        printf("\n\nNumero du secteur : ");
        gets(versement.nosect);
    }

    fclose(fichierVersements);

    return 0;
}
