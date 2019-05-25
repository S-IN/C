/* ========================================================================== */
/* Projet : initExFac3                                                        */
/* -------------------------------------------------------------------------- */
/* Saisir un entier                                                           */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>

int main()
{
   char ch;              /* caractere tape                                    */
   int entier;           /* valeur de l'entier deja saisi                     */

/* -------------------------------------------------------------------------- */
/* Saisie et controle                                                         */
/* -------------------------------------------------------------------------- */
   entier = 0;

   puts("Tapez un nombre entier, puis validez (Entree)");
   ch = _getch();

   while (ch != '\r')
   {
      if ((ch >= '0') && (ch <= '9'))
      {
         _putch(ch);
         entier = (entier * 10) + (ch - '0');
      }

      ch = _getch();
   }

   printf("\nVous avez entre %d\n\n", entier);

   return 0;
}
