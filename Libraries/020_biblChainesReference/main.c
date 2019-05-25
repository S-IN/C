/* ========================================================================== */
/* Test des utilitaires de traitement de chaines (reference stagiaires)       */
/* ========================================================================== */

#include <string.h>
#include <stdio.h>

#include "\\10.75.96.101\User\Stagiaires\Group64\Reference\C\utilitaires\entetes\chaines.h"


/* -------------------------------------------------------------------------- */
/* Programme principal de test                                                */
/* -------------------------------------------------------------------------- */

int main()
{
   char chaine[81] = "";
   int longueur;
   int n;
   double r;
   char result[81];

/* -------------------------------------------------------------------------- */
/* Affichage de la chaine vide                                                */
/* -------------------------------------------------------------------------- */
   puts(chaine);
   longueur = strlen(chaine);
   printf("longueur = %d\n\n", longueur);


/* -------------------------------------------------------------------------- */
/* Remplir la chaine avec des '.' entre les caracteres numero 6 et 19         */
/* -------------------------------------------------------------------------- */
   remplirChaine(chaine, '.', 6, 19);
   puts(chaine);
   longueur = strlen(chaine);
   printf("longueur = %d\n\n", longueur);

/* -------------------------------------------------------------------------- */
/* Remplir la chaine avec des '*' ent\\10.75.96.101\User\Stagiaires\Group64\Reference\C\utilitaires\entetesre les caracteres numero 0 et 8          */
/* -------------------------------------------------------------------------- */
   remplirChaine(chaine, '*', 0, 8);
   puts(chaine);
   longueur = strlen(chaine);
   printf("longueur = %d\n\n", longueur);

/* -------------------------------------------------------------------------- */
/* Remplir la chaine avec des '-' entre les caracteres numero 25 et 28        */
/* -------------------------------------------------------------------------- */
   remplirChaine(chaine, '-', 25, 28);
   puts(chaine);
   longueur = strlen(chaine);
   printf("longueur = %d\n\n", longueur);

/* -------------------------------------------------------------------------- */
/* Conversion d'un reel (double) en chaine                                    */
/* -------------------------------------------------------------------------- */
   r = 1563.5498;
   doubleChaineFr(r, 3, result);
   puts(result);

/* -------------------------------------------------------------------------- */
/* Remise a blanc (vide) de la chaine et insertion de la chaine result        */
/* -------------------------------------------------------------------------- */
   strcpy(chaine, "");
   placeSousChaine(chaine, result, 19, 'd');
   puts(chaine);
   printf("\n");

/* -------------------------------------------------------------------------- */
/* Insertion de la chaine "fumier"                                            */
/* -------------------------------------------------------------------------- */
   placeSousChaine(chaine, "fumier", 10, 'g');
   puts(chaine);

   longueur = strlen(chaine);
   printf("longueur = %d\n\n", longueur);


/* -------------------------------------------------------------------------- */
/* Saisie d'une chaine et conversion en reel (double)                         */
/* -------------------------------------------------------------------------- */
/* Le programme affiche le resultat des controles effectues dans chaineDouble */
/* et la valeur du reel si tout s'est bien passe (n == 0)                     */
/* -------------------------------------------------------------------------- */
   printf("Entrer un nombre : ");
   gets(chaine);
   n = chaineDouble(chaine, &r);

   switch (n)
   {
   case 0 :
      printf("r = %f\n\n", r);
      break;
   case 1 :
      printf("Chaine vide\n\n");
      break;
   case 2 :
      printf("Trop de virgules decimales\n\n");
      break;
   case 3 :
      printf("Nombre mal ecrit\n\n");
      break;
   }

/* -------------------------------------------------------------------------- */
/* Test de la fonction isole                                                  */
/* -------------------------------------------------------------------------- */
   strcpy(chaine, "12345;gineste   michel; fumier;15 222,15");
   printf("Chaine a decouper : %s\n\n", chaine);

   n = isole(chaine, result);

   while(n == 0)
   {
      puts(result);
      n = isole(chaine, result);
   }
   puts(result);

   return 0;
}
