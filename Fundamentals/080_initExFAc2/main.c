/* ========================================================================== */
/* Projet : initExFac2                                                        */
/* -------------------------------------------------------------------------- */
/* Deuxieme etape : boucle de saisie du mot de passe (FUMIER)                 */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>

int main()
{
   char ch;              /* caractere tape                                    */
   int nbCh;             /* nombre de caracteres deja tapes                   */
   int nbChCorrect;      /* nombre de caracteres corrects deja tapes          */

/* -------------------------------------------------------------------------- */
/* Saisie et controle du mot de passe                                         */
/* -------------------------------------------------------------------------- */
/* Premiere saisie du mot de passe                                            */
/* -------------------------------------------------------------------------- */
   nbCh = 0;
   nbChCorrect = 0;

   puts("Tapez votre mot de passe, puis validez (Entree)");
   ch = _getch();
   nbCh++;

   while (ch != '\r')
   {
      _putch('x');

      switch (nbCh)
      {
      case 1 :
         if (ch == 'F') nbChCorrect++;
         break;
      case 2 :
         if (ch == 'U') nbChCorrect++;
         break;
      case 3 :
         if (ch == 'M') nbChCorrect++;
         break;
      case 4 :
         if (ch == 'I') nbChCorrect++;
         break;
      case 5 :
         if (ch == 'E') nbChCorrect++;
         break;
      case 6 :
         if (ch == 'R') nbChCorrect++;
         break;
      }

      ch = _getch();
      nbCh++;
   }

/* -------------------------------------------------------------------------- */
/* Boucle de saisie du mot de passe                                           */
/* -------------------------------------------------------------------------- */
   while ((nbCh != 7) || (nbChCorrect != 6))
   {
      printf("\n\nMot de passe incorrect\n");

      nbCh = 0;
      nbChCorrect = 0;

      puts("Tapez votre mot de passe, puis validez (Entree)");
      ch = _getch();
      nbCh++;

      while (ch != '\r')
      {
         _putch('x');

         switch (nbCh)
         {
         case 1 :
            if (ch == 'F') nbChCorrect++;
            break;
         case 2 :
            if (ch == 'U') nbChCorrect++;
            break;
         case 3 :
            if (ch == 'M') nbChCorrect++;
            break;
         case 4 :
            if (ch == 'I') nbChCorrect++;
            break;
         case 5 :
            if (ch == 'E') nbChCorrect++;
            break;
         case 6 :
            if (ch == 'R') nbChCorrect++;
            break;
         }

         ch = _getch();
         nbCh++;
      }
   }

   printf("\n\nBRAVO !\n");

   return 0;
}
