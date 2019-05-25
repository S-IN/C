/* ========================================================================== */
/* Projet : initExFac1                                                        */
/* -------------------------------------------------------------------------- */
/* Saisir un mot de passe (FUMIER)                                            */
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
/* Pour que le mot de passe soit correct, il faut que le nombre de caractere  */
/* tapes soit 7 (a cause du '\r') et que le nombre de caracteres corrects     */
/* soit 6.                                                                    */
/* -------------------------------------------------------------------------- */
   if ((nbCh == 7) && (nbChCorrect == 6))
      printf("\nBRAVO !\n\n");
   else
      printf("\nVous etes NUL !!!\n\n");

   return 0;
}
