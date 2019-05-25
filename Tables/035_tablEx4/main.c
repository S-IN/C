/* ========================================================================== */
/* Projet : tablEx4                                                           */
/* -------------------------------------------------------------------------- */
/* Tableau à une dimension                                                    */
/* Dire si une valeur est presente dans un tableau                            */
/* Recherche dichotomique                                                     */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <stdio.h>

int main()
{
   int tableau[10] = {1, 3, 5, 7, 8, 14, 23, 33, 45, 112};  /* Tableau trie   */

   int i;                    /* Indice de parcours du tableau                 */
   int valeur;               /* Valeur a cherche dans le tableau              */
   int trouve;               /* 'o' valeur trouvee, 'n' non trouvee           */
   int debut, fin;           /* indices de debut et de fin de la zone a       */
                             /* examiner                                      */

/* -------------------------------------------------------------------------- */
/* Saisie de la valeur                                                        */
/* -------------------------------------------------------------------------- */
   printf("Entrez la valeur a chercher : ");
   scanf("%d", &valeur);

/* -------------------------------------------------------------------------- */
/* Calcul du nombre cherche                                                   */
/* -------------------------------------------------------------------------- */
   trouve = 'n';
   debut = 0;
   fin = 9;
   i = 0;

   do
   {
      i = (debut + fin) / 2;
      printf("i : %d\n", i);
      if (tableau[i] == valeur)
      {
         trouve = 'o';
      }
      else
      {
         if (tableau[i] > valeur)
         {
            fin = i - 1;
         }
         else
         {
            debut = i + 1;
         }
      }
   }
   while ((debut <= fin) && (trouve == 'n'));

   if (trouve == 'o')
   {
      printf("\n\nLa valeur %d est trouvee dans le tableau\n\n", valeur);
   }
   else
   {
      printf("\n\nLa valeur %d n'est pas trouvee dans le tableau\n\n", valeur);
   }

   return 0;
}
