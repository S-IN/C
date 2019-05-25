/* ========================================================================== */
/* Projet : initExFac4                                                        */
/* -------------------------------------------------------------------------- */
/* Saisir un reel (virgule flottante)                                         */
/* -------------------------------------------------------------------------- */
/* Auteur : Michel Gineste                                                    */
/* ========================================================================== */

#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
   char ch;              /* caractere tape                                    */
   int nbCh;             /* nombre de caracteres valides tapes                */
   double nombre;        /* valeur du nombre saisi                            */
   int partieEntiere;    /* partie entiere du nombre tape                     */
   int partieDecimale;   /* partie decimale du nombre tape                    */
   int nombreDecimales;  /* nombre de decimales du nombre tape                */
   char virgule;         /* nombre de virgules tapees (limite a 1)            */
   char signe;           /* signe du nombre, par defaut positif (1)           */

/* -------------------------------------------------------------------------- */
/* Saisie et controles                                                        */
/* -------------------------------------------------------------------------- */
   partieEntiere = 0;
   partieDecimale = 0;
   nombreDecimales = 0;
   virgule = 0;
   signe = 1;

   nbCh = 0;
   puts("Tapez un nombre reel, puis validez (Entree)");
   ch = _getch();

   while (ch != '\r')
   {
      if ((ch == '+') && (nbCh == 0))
      {
         _putch(ch);
         nbCh++;
      }

      if ((ch == '-') && (nbCh == 0))
      {
         signe = -1;
         _putch(ch);
         nbCh++;
      }

      if ((ch == ',') && (virgule == 0))
      {
         virgule = 1;
         _putch(ch);
         nbCh++;
      }

      if ((ch >= '0') && (ch <= '9') && (virgule == 0))
      {
         partieEntiere = (partieEntiere * 10) + (ch - '0');
         _putch(ch);
         nbCh++;
      }

      if ((ch >= '0') && (ch <= '9') && (virgule == 1))
      {
         partieDecimale = (partieDecimale * 10) + (ch - '0');
         nombreDecimales++;
         _putch(ch);
         nbCh++;
      }

      ch = _getch();
   }

/* -------------------------------------------------------------------------- */
/* Calcul final                                                               */
/* -------------------------------------------------------------------------- */

   printf("\nPartie entiere   : %d\n", partieEntiere);
   printf("\nPartie decimale  : %d\n", partieDecimale);
   printf("\nNombre decimales : %d\n", nombreDecimales);

   nombre = signe *
            (partieEntiere + (partieDecimale * pow(10, - nombreDecimales)));

   printf("\n\nValeur : %f\n", nombre);

   return 0;
}
